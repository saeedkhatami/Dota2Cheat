#pragma once
#include <cstdint>
#include <iostream>
#include <Windows.h>
#include "Input.h"

#define PI 3.1415926

inline void PAUSE() {
	std::cout << "PAUSE" << '\n';
	while (!IsKeyPressed(VK_NUMPAD3)) {
	}
}


#define ENT_HANDLE uint32_t
#define ENT_HANDLE_MASK 0x7fff
#define H2IDX(H) (H & ENT_HANDLE_MASK) // Entity handle to entity index
#define HVALID(H) (H != 0xFFFFFFFF)

#define u64 unsigned long long
#define cc const char*

extern HANDLE CurProcHandle;
extern int CurProcId;

struct Vector2 {
	float x, y;
	inline Vector2(float x, float y) : x(x), y(y) {

	}
	inline float DistanceTo(const Vector2& v) {
		return sqrtf(powf(v.x - x, 2) + powf(v.y - y, 2));
	}
};

struct Vector3 {
	static Vector3 Zero;
	float x, y, z;
	inline Vector3(float x, float y, float z) :x(x), y(y), z(z) {

	}

	friend Vector3 operator+(const Vector3& v1, const Vector3& v2) {
		return Vector3(v1.x + v2.x, v1.y + v2.y, v2.z + v1.z);
	}
	friend Vector3 operator*(const Vector3& v1, float n) {
		return Vector3(v1.x * n, v1.y * n, v1.z * n);
	}


	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
		os << "{" << ' '
			<< "X: " << vec.x << ' '
			<< "Y: " << vec.y << ' '
			<< "Z: " << vec.z << ' '
			<< "}";
		return os;
	}
};

//struct Color4f {
//	float RGBA[4] = { 0,0,0,0 };
//	inline Color4f(float r, float g, float b, float a) : RGBA{r,g,b,a} {
//
//	}
//};

//mathematicians hate this one trick!
//yeah, to check for radius, you can actually omit the sqrt and just square the radius
inline float IsWithinRadius(Vector2 p1, Vector2 p2, float radius) {
	return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) <= radius * radius;
}

//credits to Liberalist from YouGame
//very handy classes
class Function {
public:
	void* ptr;
	inline Function(uintptr_t ptr) : ptr((void*)ptr) {

	}
	template<typename ...T>
	inline void* __fastcall operator()(T... t) {
		return (void*)((u64(__fastcall*)(T...))ptr)(t...);
	}
	template<typename V, typename ...T>
	inline V __fastcall Execute(T... t) {
		return ((V(__fastcall*)(T...))ptr)(t...);
	}

};
inline u64 GetAbsoluteAddress(u64 instruction_ptr, int offset, int size)
{
	return instruction_ptr + *(int*)(instruction_ptr + offset) + size;
}
inline Function getvfunc(void* instance, int index)
{
	uintptr_t vtable = *((uintptr_t*)(instance));
	uintptr_t entry = vtable + sizeof(uintptr_t) * index;
	return Function(*(uintptr_t*)entry);
}
template<typename T, typename Z>
inline bool StringsMatch(T a, Z b) {
	return !strcmp((cc)a, (cc)b);
}
template<typename T, typename Z>
inline void MemCopy(T dst, Z src, size_t size) {
	memcpy((void*)dst, (const void*)src, size);
}
template <typename I>
std::string n2hexstr(I w, size_t hex_len = sizeof(I) << 1) {
	static const char* digits = "0123456789ABCDEF";
	std::string rc(hex_len, '0');
	for (size_t i = 0, j = (hex_len - 1) * 4; i < hex_len; ++i, j -= 4)
		rc[i] = digits[((u64)w >> j) & 0x0f];
	return rc;
}
inline void Log(const char* str) {
	std::cout << "[LOG] " << str << '\n';
};
class NormalClass {
public:
	template<typename T>
	inline T Member(int offset/*, T defaultValue = T{}*/) {
		//if (!offset)
		//	return defaultValue;
		return *(T*)((uintptr_t)this + offset);
	}
};
class VClass {
public:
	virtual void dummy_fn() = 0; // so that the classes have a vtable
	template<typename T>
	inline T Member(int offset/*, T defaultValue = T{}*/) {
		//if (!offset)
		//	return defaultValue;
		return *(T*)((uintptr_t)this + offset);
	}
	inline Function GetVFunc(int index)
	{
		uintptr_t vtable = *((uintptr_t*)(this));
		uintptr_t entry = vtable + sizeof(uintptr_t) * index;
		return Function(*(uintptr_t*)entry);
	}
	template<uint32_t index, typename RET = void*, typename ...T>
	inline RET CallVFunc(T... t) {
		return GetVFunc(index).Execute<RET>(this, t...);
	}
};