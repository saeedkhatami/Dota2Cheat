#pragma once
#include "../SDK/pch.h"
#include "../CheatSDK/include.h"
#include "../Modules/Hacks/AutoAccept.h"
#include <curl/curl.h>

namespace Hooks {

	typedef void(*RunScriptFn)(VClass*, VClass*, const char*, const char*, int, int, bool);
	inline RunScriptFn oRunScript;

	void hkRunScript(VClass* thisptr, VClass* panel, const char* entireJSCode, const char* pathToXMLContext, int int1, int int2, bool alreadyCompiled);

	inline Signatures::CDOTA_DB_Popup_AcceptMatchFn oCDOTA_DB_Popup_AcceptMatch;
	inline void* hkCDOTA_DB_Popup_AcceptMatch(VClass* thisptr, Panorama::CPanel2D* unk0, const char* caption, Panorama::CPanel2D* unk1, bool isLP, const char* subtitle) {		
		Modules::AutoAccept.SetNotificationGameMode(subtitle);
		return oCDOTA_DB_Popup_AcceptMatch(thisptr, unk0, caption, unk1, isLP, subtitle);
	}
}