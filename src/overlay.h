#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dwmapi.h>
#include "thirdparty/imgui/imgui.h"
#include "thirdparty/imgui/imgui_impl_win32.h"
#include "thirdparty/imgui/imgui_impl_dx9.h"
#include "Vars.h"
#include "UI.h";

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "Dwmapi.lib")

namespace Overlay {
	static ULONG Width = GetSystemMetrics(SM_CXSCREEN);
	static ULONG Height = GetSystemMetrics(SM_CYSCREEN);
	
	HRESULT initWnd(HWND hWnd);
	HWND getProcessWnd(uint32_t pid);
	void setWindowTarget();
	void setupWindow();
}