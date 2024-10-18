#include "Present.h"

#include "../Modules/UI/Indicators/SpeedIndicator.h"
#include "../Modules/UI/Indicators/KillIndicator.h"

#include "../Modules/UI/BlinkRevealer.h"
#include "../Modules/UI/TPTracker.h"
#include "../Modules/UI/ParticleMaphack.h"
#include "../Modules/UI/AbilityESP/AbilityESP.h"
#include "../Modules/UI/BarAugmenter.h"
#include "../Modules/UI/UIOverhaul.h"

#include "../Modules/Hacks/SkinChanger.h"
#include "../Modules/UI/LastHitMarker.h"

#include "../CheatSDK/VTexDecoders/VTexParser.h"
#include "../CheatSDK/Shaders.h"

LRESULT WINAPI Hooks::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	KeyHandler.OnWindowMessage(uMsg, wParam);

	if (DrawData.ShowMenu) {
		bool k = ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		if (!k) return !k;
	}

	return CallWindowProcA(DrawData.Dx.oWndProc, hWnd, uMsg, wParam, lParam);
}

void InitImGui() {
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(DrawData.Dx.Window);
	ImGui_ImplDX11_Init(DrawData.Dx.pDevice, DrawData.Dx.pContext);

	LogI("Loading fonts...");

	// ImGui takes ownership of the loaded memory by default
	// Of course, we don't want to try to delete a constant array and get a SEGFAULT
	ImFontConfig fontCfg{};
	fontCfg.FontDataOwnedByAtlas = false;
	for (int i = 2; i < 30; i += 2) {
		DrawData.Fonts["MSTrebuchet"][i] = io.Fonts->AddFontFromFileTTF(R"(C:\Windows\Fonts\trebuc.ttf)", i, nullptr, io.Fonts->GetGlyphRangesDefault());
		DrawData.Fonts["Monofonto"][i] = io.Fonts->AddFontFromMemoryTTF((void*)Fonts::Monofonto, IM_ARRAYSIZE(Fonts::Monofonto), i, &fontCfg, io.Fonts->GetGlyphRangesDefault());
	}

	ImGui::StyleColorsClassic();
}

bool InitDX11(IDXGISwapChain* pSwapChain) {
	if (!SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&DrawData.Dx.pDevice)))
		return false;
	// D3D Context
	DrawData.Dx.pDevice->GetImmediateContext(&DrawData.Dx.pContext);

	D3D11_RENDER_TARGET_VIEW_DESC desc{};
	memset(&desc, 0, sizeof(desc));
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

	// Saves HWND
	DXGI_SWAP_CHAIN_DESC sd;
	pSwapChain->GetDesc(&sd);
	DrawData.Dx.Window = sd.OutputWindow;

	// Initializes D3D render target view
	ID3D11Texture2D* pBackBuffer = nullptr;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	DrawData.Dx.pDevice->CreateRenderTargetView(pBackBuffer, &desc, &DrawData.Dx.mainRenderTargetView);
	pBackBuffer->Release();
	// Hooks WndProc
	DrawData.Dx.oWndProc = (WNDPROC)SetWindowLongPtr(DrawData.Dx.Window, GWLP_WNDPROC, (LONG_PTR)Hooks::WndProc);

	InitImGui();

	DrawData.Initialized = true;
	DrawData.ShowMenu = true;

	return true;
}

long Hooks::hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
	if (!DrawData.Initialized) {
		if (!InitDX11(pSwapChain))
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	auto& io = ImGui::GetIO();
	static auto defaultFont = io.Fonts->AddFontFromMemoryTTF((void*)Fonts::Roboto, IM_ARRAYSIZE(Fonts::Roboto), 18.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	texManager.ExecuteLoadCycle();

	ImGui::PushFont(DrawData.Fonts["MSTrebuchet"][24]);
	if (
		CGameUI::Get()->GetUIState() == DOTA_GAME_UI_DOTA_INGAME
		&& ctx.gameStage == GameStage::IN_GAME
		&& ctx.localHero
		) {
		Modules::AbilityESP.Draw();
		Modules::UIOverhaul.Draw();
		Modules::TPTracker.Draw();
		Modules::LastHitMarker.Draw();
		Modules::BlinkRevealer.Draw();
		Modules::ParticleMaphack.Draw();
		Modules::BarAugmenter.Draw();
		Modules::SpeedIndicator.Draw();
		Modules::KillIndicator.Draw();
	}
	ImGui::PopFont();

	ImGui::PushFont(defaultFont);

	if (DrawData.ShowMenu)
		Pages::MainMenu::Draw();

	ImGui::PopFont();

	ImGui::EndFrame();
	ImGui::Render();
	DrawData.Dx.pContext->OMSetRenderTargets(1, &DrawData.Dx.mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return oPresent(pSwapChain, SyncInterval, Flags);
}
