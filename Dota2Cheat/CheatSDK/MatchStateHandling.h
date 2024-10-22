#pragma once
#include <Dota2SDK.h>
// #include "../pch.h"

// A dota cheat's perception of reality relies on the game's stage,
// as obviously we cannot do in-game things while we're still picking heroes

inline struct CMatchStateManager {
	void EnteredPreGame();
	void EnteredInGame();
	void LeftMatch();
	void CheckForOngoingGame();

	// D2C's entity system is based on collections
	// Without such caching it doesn't retain the entity lists upon reinjection
	void CacheAllEntities();

	void OnUpdatedAssignedHero();
	void OnStateChanged(DOTA_GameState newState);
} MatchStateManager;