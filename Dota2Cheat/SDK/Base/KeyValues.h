#pragma once
#include "Memory.h"
#include "MemAlloc.h"
#include "../Interfaces/CBaseFileSystem.h"

struct KeyValues {
	// from TF2 source
	enum types_t
	{
		TYPE_NONE = 0,
		TYPE_STRING,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_PTR,
		TYPE_WSTRING,
		TYPE_COLOR,
		TYPE_UINT64,
		TYPE_COMPILED_INT_BYTE,			// hack to collapse 1 byte ints in the compiled format
		TYPE_COMPILED_INT_0,			// hack to collapse 0 in the compiled format
		TYPE_COMPILED_INT_1,			// hack to collapse 1 in the compiled format
		TYPE_NUMTYPES,
	};

	types_t GetDataType(const char* key = nullptr) const {
		static auto func = Memory::GetExport("tier0.dll", "?GetDataType@KeyValues@@QEBA?AW4types_t@CKeyValues_Data@@PEBD@Z");
		return func.Call<types_t>(this, key);
	}

	static KeyValues* MakeKV(const char* name) {
		auto kv = CMemAlloc::Get()->Alloc<KeyValues>(0x14);
		static auto ctor = Memory::GetExport("tier0.dll", "??0KeyValues@@QEAA@PEBD00@Z");
		ctor(kv, name, nullptr, nullptr);
		return kv;
	}

	bool LoadFromFile(const char* path) {
		auto func = Memory::GetExport("tier0.dll", "?LoadFromFile@KeyValues@@QEAA_NPEAVIFileSystem@@PEBD1P6A_N1PEAX@Z21@Z");
		return func.Call<bool>(this, CBaseFileSystem::Get(), path, "GAME", nullptr, nullptr, nullptr);
	}

	KeyValues* GetFirstSubKey() const {
		static auto func = Memory::GetExport("tier0.dll", "?GetFirstSubKey@KeyValues@@QEBAPEAV1@XZ");
		return func.Call<KeyValues*>(this);
	}

	KeyValues* GetNextKey() const {
		static auto func = Memory::GetExport("tier0.dll", "?GetNextKey@KeyValues@@QEBAPEAV1@XZ");
		return func.Call<KeyValues*>(this);
	}

	const char* GetName() {
		static auto func = Memory::GetExport("tier0.dll", "?GetName@KeyValues@@QEBAPEBDXZ");
		return func.Call<const char*>(this);
	}

	void Destroy() {
		static auto func = Memory::GetExport("tier0.dll", "??1KeyValues@@QEAA@XZ");
		func(this);
	}

	struct Iterator {
		KeyValues* node;

		Iterator(KeyValues* node) : node(node) {}

		bool operator!=(const Iterator& other) {
			return other.node != node;
		}

		KeyValues* operator*() const {
			return node;
		}

		Iterator operator++() {
			node = node->GetNextKey();
			return *this;
		}
	};

	void SetString(std::string_view key, std::string_view val) {
		static auto func = Memory::GetExport("tier0.dll", "?SetString@KeyValues@@QEAAXPEBD0@Z");
		func(this, key.data(), val.data());
	}

	void SetFloat(std::string_view key, float val) {
		static auto func = Memory::GetExport("tier0.dll", "?SetFloat@KeyValues@@QEAAXPEBDM@Z");
		func(this, key.data(), val);
	}
	void SetInt(std::string_view key, int val) {
		static auto func = Memory::GetExport("tier0.dll", "?SetInt@KeyValues@@QEAAXPEBDH@Z");
		func(this, key.data(), val);
	}
};
inline KeyValues::Iterator begin(KeyValues* kv) {
	return kv->GetFirstSubKey();
}

inline KeyValues::Iterator end(KeyValues*) {
	return nullptr;
}

