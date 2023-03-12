#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dwmapi.h>
#include "thirdparty/imgui/imgui.h"
#include "thirdparty/imgui/imgui_impl_win32.h"
#include "thirdparty/imgui/imgui_impl_dx9.h"
#include "sdk.h"
#include "Vars.h"
#include "UI.h";

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "Dwmapi.lib")



static ULONG Width = GetSystemMetrics(SM_CXSCREEN);
static ULONG Height = GetSystemMetrics(SM_CYSCREEN);
auto init_wndparams(HWND hWnd) -> HRESULT
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &Vars::pObject)))
		exit(3);

	ZeroMemory(&Vars::pParams, sizeof(Vars::pParams));
	Vars::pParams.Windowed = TRUE;
	Vars::pParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Vars::pParams.hDeviceWindow = hWnd;
	Vars::pParams.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	Vars::pParams.BackBufferFormat = D3DFMT_A8R8G8B8;
	Vars::pParams.BackBufferWidth = Width;
	Vars::pParams.BackBufferHeight = Height;
	Vars::pParams.EnableAutoDepthStencil = TRUE;
	Vars::pParams.AutoDepthStencilFormat = D3DFMT_D16;
	Vars::pParams.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	if (FAILED(Vars::pObject->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &Vars::pParams, 0, &Vars::pDevice))) {
		Vars::pObject->Release();
		exit(4);
	}
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.IniFilename = NULL;
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arialbd.ttf", 13);
	ImGui::StyleColorsLight();
	UI::style();

	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX9_Init(Vars::pDevice);
	return S_OK;
}

auto get_process_wnd(uint32_t pid) -> HWND
{
	std::pair<HWND, uint32_t> params = { 0, pid };
	BOOL bResult = EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
		auto pParams = (std::pair<HWND, uint32_t>*)(lParam);
		uint32_t processId = 0;

		if (GetWindowThreadProcessId(hwnd, reinterpret_cast<LPDWORD>(&processId)) && processId == pParams->second) {
			SetLastError((uint32_t)-1);
			pParams->first = hwnd;
			return FALSE;
		}

		return TRUE;

		}, (LPARAM)&params);

	if (!bResult && GetLastError() == -1 && params.first)
		return params.first;

	return NULL;
}

auto set_window_target() -> void
{
	while (true) {
		Vars::gameWnd = get_process_wnd(Vars::gPid);
		if (Vars::gameWnd) {
			ZeroMemory(&Vars::gameRect, sizeof(Vars::gameRect));
			GetWindowRect(Vars::gameWnd, &Vars::gameRect);
			DWORD dwStyle = GetWindowLong(Vars::gameWnd, GWL_STYLE);
			if (dwStyle & WS_BORDER)
			{
				Vars::gameRect.top += 32;
				Height -= 39;
			}
			Vars::screenCenterX = Width / 2;
			Vars::screenCenterY = Height / 2;
			MoveWindow(Vars::myWnd, Vars::gameRect.left, Vars::gameRect.top, Width, Height, true);
		}
	}
}

auto setup_window() -> void
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)set_window_target, 0, 0, 0);
	g_width = GetSystemMetrics(SM_CXSCREEN);
	g_height = GetSystemMetrics(SM_CYSCREEN);
	WNDCLASSEXA wcex = {
		sizeof(WNDCLASSEXA),
		0,
		DefWindowProcA,
		0,
		0,
		nullptr,
		LoadIcon(nullptr, IDI_APPLICATION),
		LoadCursor(nullptr, IDC_ARROW),
		nullptr,
		nullptr,
		("Overlay"),
		LoadIcon(nullptr, IDI_APPLICATION)
	};

	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);

	RegisterClassExA(&wcex);

	Vars::myWnd = CreateWindowExA(NULL, ("Overlay"), ("Overlay"), WS_POPUP, Rect.left, Rect.top, Rect.right, Rect.bottom, NULL, NULL, wcex.hInstance, NULL);
	SetWindowLong(Vars::myWnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	SetLayeredWindowAttributes(Vars::myWnd, RGB(0, 0, 0), 255, LWA_ALPHA);

	MARGINS margin = { -1 };
	DwmExtendFrameIntoClientArea(Vars::myWnd, &margin);

	ShowWindow(Vars::myWnd, SW_SHOW);
	UpdateWindow(Vars::myWnd);
}
