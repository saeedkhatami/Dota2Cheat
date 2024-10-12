#include "CRenderGameSystem.h"
#include "../Interfaces/CEngineServiceMgr.h"
#include "../Base/Logging.h"

bool CRenderGameSystem::GetVectorInScreenSpace(const Vector& point, Vector2D& screen) const
{
	const float* worldToSurface = WorldToProjectionMatrix();

	screen[0] = worldToSurface[0] * point[0] + worldToSurface[1] * point[1] + worldToSurface[2] * point[2] + worldToSurface[3];
	screen[1] = worldToSurface[4] * point[0] + worldToSurface[5] * point[1] + worldToSurface[6] * point[2] + worldToSurface[7];

	const float w = worldToSurface[12] * point[0] + worldToSurface[13] * point[1] + worldToSurface[14] * point[2] + worldToSurface[15];

	if (w < 0.001f)
		return false;

	const float ww = 1.f / w;
	screen[0] *= ww;
	screen[1] *= ww;

	static int resolut[2] = { 0 };
	if (!resolut[0] || !resolut[1])
	{
		CEngineServiceMgr::Get()->GetEngineSwapChainSize(&resolut[0], &resolut[1]);

		if (resolut[0] == 0 || resolut[1] == 0) {
			static std::once_flag f;
			static auto fName = __FUNCTION__;
			std::call_once(f, [] { LogFE("{}: {}", fName, "GetEngineSwapChainSize returned incorrect data!"); });
			return false;
		}
	}

	screen.x = (resolut[0] + screen.x * resolut[0] + 1) / 2.f;
	screen.y = (resolut[1] - screen.y * resolut[1] + 1) / 2.f;

	return true;
}