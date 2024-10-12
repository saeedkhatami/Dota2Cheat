#pragma once
#include "../Base/VClass.h"
#include "../Base/NormalClass.h"
#include "../Base/Definitions.h"
#include "../Base/CUtlVector.h"
#include "../Interfaces/Network/CNetworkMessages.h"

#include "../Base/Vector.h"
#include "../VMI.h"

class CBaseEntity;

// Enum from animationsystem.dll, dumped by Liberalist
enum ParticleAttachment_t : int32_t {
	PATTACH_INVALID = -1,
	PATTACH_ABSORIGIN = 0,
	PATTACH_ABSORIGIN_FOLLOW = 1,
	PATTACH_CUSTOMORIGIN = 2,
	PATTACH_CUSTOMORIGIN_FOLLOW = 3,
	PATTACH_POINT = 4,
	PATTACH_POINT_FOLLOW = 5,
	PATTACH_EYES_FOLLOW = 6,
	PATTACH_OVERHEAD_FOLLOW = 7,
	PATTACH_WORLDORIGIN = 8,
	PATTACH_ROOTBONE_FOLLOW = 9,
	PATTACH_RENDERORIGIN_FOLLOW = 10,
	PATTACH_MAIN_VIEW = 11,
	PATTACH_WATERWAKE = 12,
	PATTACH_CENTER_FOLLOW = 13,
	PATTACH_CUSTOM_GAME_STATE_1 = 14,
	PATTACH_HEALTHBAR = 15,
	MAX_PATTACH_TYPES = 16,
};

// Struct used when creating a particle
class CRecipientFilter
{
public:
	char                pad_0x0000[0x8];   // 0x0000
	NetChannelBufType_t m_nBufType;        // 0x0008
	unsigned char       m_bInitMessage;    // 0x000C
	char                pad_0x000D[0x3];   // 0x000D
	CUtlVector<int>     m_Recipients;      // 0x0010
	char _pad0[0x108];                     // 0x0028
	unsigned char m_bUsingPredictionRules; // 0x0130
	unsigned char m_bIgnorePredictionCull; // 0x0131
	char _pad1[0x6];                       // 0x0132
};                                         // Size=0x0138

struct CreateParticleInfo
{
	const char* m_szParticleName;
	ParticleAttachment_t m_particleAttachment;
	CBaseEntity* m_pTargetEntity;
private:
	void* unk[5] = {
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr
	};
};

static_assert(sizeof(CreateParticleInfo) == 0x40);


class CParticleCollectionRendererVecInput : public VClass {
public:
	FIELD(Color, LiteralColor, Netvars::CParticleVecInput::m_LiteralColor);
};

enum ParticleColorBlendType_t {
	PARTICLE_COLOR_BLEND_MULTIPLY = 0,
	PARTICLE_COLOR_BLEND_MULTIPLY2X = 1,
	PARTICLE_COLOR_BLEND_DIVIDE = 2,
	PARTICLE_COLOR_BLEND_ADD = 3,
	PARTICLE_COLOR_BLEND_SUBTRACT = 4,
	PARTICLE_COLOR_BLEND_MOD2X = 5,
	PARTICLE_COLOR_BLEND_SCREEN = 6,
	PARTICLE_COLOR_BLEND_MAX = 7,
	PARTICLE_COLOR_BLEND_MIN = 8,
	PARTICLE_COLOR_BLEND_REPLACE = 9,
	PARTICLE_COLOR_BLEND_AVERAGE = 10,
	PARTICLE_COLOR_BLEND_NEGATE = 11,
	PARTICLE_COLOR_BLEND_LUMINANCE = 12,
};


class C_OP_RenderSprites : public VClass {
public:
	IGETTER(CParticleCollectionRendererVecInput, GetVecColorScale, Netvars::CBaseRendererSource2::m_vecColorScale);
	FIELD(ParticleColorBlendType_t, BlendType, Netvars::CBaseRendererSource2::m_nColorBlendType);
};

class CParticleSystemDefinition : public VClass {
public:
	GETTER(CUtlVector<C_OP_RenderSprites*>, GetRenderers, Netvars::CParticleSystemDefinition::m_Renderers);
};


class CParticleCollection : public VClass {
public:
	struct ParticleDef {
		CParticleSystemDefinition* pDef;
		const char* szResource;
	};

	FIELD(ParticleDef*, Definition, 0x18);
	VGETTER(bool, GetRenderingEnabled, VMI::CParticleCollection::SetRenderingEnabled - 1);
	void SetRenderingEnabled(bool value) {
		GetVFunc(VMI::CParticleCollection::SetRenderingEnabled)(value);
	}
};

struct CNewParticleEffect : public VClass {
	GETTER(CParticleCollection*, GetParticleCollection, 0x20);

	CNewParticleEffect* SetControlPoint(int idx, const Vector& pos) {
		auto coll = GetParticleCollection();
		coll->GetVFunc(VMI::CParticleCollection::SetControlPoint)(idx, &pos);
		return this;
	}
};

struct ParticleWrapper {
	CreateParticleInfo info{};
	CNewParticleEffect* particle{};
	ENT_HANDLE handle = INVALID_HANDLE;

	void Invalidate() {
		particle = nullptr;
		handle = INVALID_HANDLE;
		info = CreateParticleInfo{};
	}
};

class CDOTAParticleManager : public VClass {
	static inline std::vector<ParticleWrapper> particles{};
public:
	struct ParticleContainer : public NormalClass {
		GETTER(CNewParticleEffect*, GetParticle, 0x10);
		GETTER(uint32_t, GetHandle, 0x2C);
	};
	static inline void(__fastcall* DestroyParticleFunc)(void* thisptr, ENT_HANDLE handle, bool unk1, bool unk2);

	GETTER(CUtlVector<ParticleContainer*>, GetParticles, 0x80);
	FIELD(uint32_t, Handle, 0xD0); // offset in function called by JS CreateParticle binding (7.36: E8 ? ? ? ? 83 7D 67 FF)

	ParticleWrapper CreateParticle(const char* name, ParticleAttachment_t attachType, CBaseEntity* ent);
	void DestroyParticle(uint32_t handle);
	void DestroyParticle(ParticleWrapper& info);

	void OnExitMatch();

	static CDOTAParticleManager* Get();
};

