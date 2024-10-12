#include "AutoDodge.h"

void Modules::AutoDodge::OnFrame() {
	if (!Config::AutoDodge::Enabled
		|| !CProjectileMgr::Get())
		return;

	if (!HeroData[ctx.localHero].Items["manta"] && !HeroData[ctx.localHero].Items["bottle"])
		return;

	for (auto proj : CProjectileMgr::Get()->m_pTrackingProjectiles) {
		if (!proj)
			continue;

		if (proj->m_bIsAttack)
			continue;

		CNPC
			* target = proj->m_hTarget,
			* source = proj->m_hSource;

		if (target != ctx.localHero ||
			(source && source->IsSameTeam(ctx.localHero)))
			continue;

		//if (counterspell && counterspell->GetCooldown() == 0)
		//	useTime = 1.2f;

		{
			auto dist = proj->m_vLocation.As<Vector2D>().DistTo(target->GetPos().As<Vector2D>()) - target->GetHullRadius();
			auto timeToHit = dist / proj->m_iMoveSpeed;
			if (timeToHit > 0.05f)
				continue;
		}

		auto usedItem = HeroData[ctx.localHero].Items["bottle"] ? HeroData[ctx.localHero].Items["bottle"] : HeroData[ctx.localHero].Items["manta"];
		//if (counterspell && counterspell->GetCooldown() == 0)
		//	usedItem = counterspell;
		//else
		if (!usedItem ||
			(
				usedItem == HeroData[ctx.localHero].Items["bottle"] && // if we can use bottle
				usedItem->Member<DOTA_RUNES>(Netvars::C_DOTA_Item_EmptyBottle::m_iStoredRuneType) != DOTA_RUNE_ILLUSION // and it has no illusion rune
				&& !((usedItem = HeroData[ctx.localHero].Items["manta"]) && // and if we don't have manta
					usedItem->GetCooldown() == 0) // or it's on cooldown
				)
			)
			continue;

		ctx.localPlayer->PrepareOrder(
			Order()
			.SetType(DOTA_UNIT_ORDER_CAST_NO_TARGET)
			.SetAbilityIndex(usedItem->GetIndex())
			.SetIssuer(ctx.localHero)
			.SetIssuerType(DOTA_ORDER_ISSUER_PASSED_UNIT_ONLY)
		);

		break;
	}
}
