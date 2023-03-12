#pragma once
#include <d3d9.h>
#include <d3d9types.h>

namespace Vars {
	inline IDirect3D9Ex* pObject = NULL;
	inline IDirect3DDevice9Ex* pDevice = NULL;
	inline D3DPRESENT_PARAMETERS pParams = { NULL };
	
	inline HWND myWnd = NULL;
	inline HWND gameWnd = NULL;
	inline MSG message = { NULL };

	inline RECT gameRect = { NULL };
	inline D3DPRESENT_PARAMETERS d3dpp;

	inline DWORD screenCenterX;
	inline DWORD screenCenterY;

	inline HANDLE driverHandle;

	inline uintptr_t gPid;
	inline uintptr_t gBase;


	inline int activeTab = 1;
	inline int keystatus = 0;
};

