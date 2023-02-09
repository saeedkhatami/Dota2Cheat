#pragma once
#include "sdk.h"

namespace UIState {

	namespace Menu {

	}

	inline const char* WeatherList[] = { "Default", "Winter", "Rain", "MoonBeam", "Pestilence", "Harvest", "Sirocco", "Spring", "Ash", "Aurora" };

	inline bool HeroVisibleToEnemy = false;

	inline int CircleRadius = 1200;
	inline Vector3 CircleRGB{0,0,0};

	inline int isVisibleRadius = 75; // small circle around the hero
	inline Vector3 CircleVisibleColor = { 255,0,0 }; // red color
}