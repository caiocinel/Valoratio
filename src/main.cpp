#include <Windows.h>
#include <string>
#include "thirdparty/wndhide.h"
#include "thirdparty/KdMapper/kdmapper.hpp"
#include "sdk.h"
#include "overlay.h"
#include "UI.h"


inline HANDLE iqvw64e_device_handle;
int hitbux;

void aimbot()
{
	try
	{
		FMinimalViewInfo2 camera = driver.read<FMinimalViewInfo2>(gcameramanager + 0x1FE0 + 0x10);
		int hitboxid;
		float aimfov = settings::fov;
		int dwIndex = SDK::ActorLoop(&aimfov);
		if (dwIndex < 0) return;
		FVector pLocalCameraRot = driver.read<FVector>(glocalplayercontroller + CAMERA_ROT);
		if (settings::hitbox == 0)
			hitboxid = 8;
		else if (settings::hitbox == 1)
			hitboxid = 7;
		else if (settings::hitbox == 2)
			hitboxid = 5;
		if (settings::aimbot)
		{
			if (GetAsyncKeyState(settings::aimkey))
			{
				EnemyPtr enemy = enemy_array[dwIndex];
				FVector neck_position = SDK::GetBone2(enemy.mesh_ptr, hitboxid);
				FVector root_position = driver.read<FVector>(enemy.root_component_ptr + ROOT_POS);
				if (neck_position.z <= root_position.z)
				{
					return;
				}
				FVector localView = driver.read<FVector>(glocalplayercontroller + CONTROL_ROT);
				FVector vecCaclculatedAngles = SDK::fhgfsdhkfshdghfsd205(camera.Location, neck_position);
				FVector angleEx = SDK::CaadadalcAngle(camera.Location, neck_position);
				FVector fin = FVector(vecCaclculatedAngles.y, angleEx.y, 0);
				if (settings::rcs) {
					FVector delta = fin - localView;
					FVector TargetAngle = localView + delta;
					SDK::Clamp(TargetAngle);
					SDK::RCS(TargetAngle, camera.Rotation, settings::smooth);
					float temp = SDK::GetFov(pLocalCameraRot, vecCaclculatedAngles);
				}
				else {
					FVector delta = fin - localView;
					SDK::NormalizeAngles(delta);
					FVector TargetAngle = localView + (delta / settings::smooth);
					SDK::NormalizeAngles(TargetAngle);
					driver.write<FVector>(glocalplayercontroller + CONTROL_ROT, TargetAngle);
					float temp = SDK::GetFov(pLocalCameraRot, vecCaclculatedAngles);
				}
			}
		}

		if (GetAsyncKeyState(VK_LBUTTON) && settings::silentaim == true)
		{
			EnemyPtr enemy = enemy_array[dwIndex];

			FVector oldpos;
			FVector neck_position = SDK::GetBone2(enemy.mesh_ptr, 8);
			FVector localView = driver.read<FVector>(glocalplayercontroller + CONTROL_ROT);
			FVector vecCaclculatedAngles = SDK::fhgfsdhkfshdghfsd205(camera.Location, neck_position);
			FVector angleEx = SDK::CaadadalcAngle(camera.Location, neck_position);
			FVector fin = FVector(vecCaclculatedAngles.y, angleEx.y, 0);
			FVector delta = fin - localView;
			SDK::NormalizeAngles(delta);
			FVector TargetAngle = localView + (delta);
			SDK::NormalizeAngles(TargetAngle);
			oldpos = driver.read<FVector>(glocalplayercontroller + CONTROL_ROT);
			driver.write<FVector>(glocalplayercontroller + CONTROL_ROT, TargetAngle);
			Sleep(15);
			driver.write<FVector>(glocalplayercontroller + CONTROL_ROT, oldpos);
			Sleep(50);
		}
	}
	catch (std::exception e)
	{
	}
}
void cache()
{
	while (true)
	{
		uintptr_t UWorld = driver.read2<uintptr_t>(Vars::gBase + 0x50);
		uintptr_t GameInstance = driver.read2<uintptr_t>(UWorld + GAME_INSTANCE);
		uintptr_t PersistentLevel = driver.read2<uintptr_t>(UWorld + PERSISTENT_LEVEL);
		uintptr_t LocalPlayers_Array = driver.read2<uintptr_t>(GameInstance + LOCALPLAYERS_ARRAY);
		uintptr_t LocalPlayer = driver.read2<uintptr_t>(LocalPlayers_Array);
		glocalplayercontroller = driver.read2<uintptr_t>(LocalPlayer + PLAYER_CONTROLER);
		glocalpawn = driver.read2<uintptr_t>(glocalplayercontroller + LOCALPLAYERPAWN);
		glocaldamagehandler = driver.read2<uintptr_t>(glocalpawn + DAMAGE_HANDLER);
		uintptr_t LocalPlayerState = driver.read2<uintptr_t>(glocalpawn + PLAYER_STATE);
		uintptr_t LocalTeamComponent = driver.read2<uintptr_t>(LocalPlayerState + TEAM_COMP);
		glocalteamid = driver.read2<int>(LocalTeamComponent + TEAM_ID);
		gcameramanager = driver.read2<uintptr_t>(glocalplayercontroller + CAMERA_MANAGER);
		uintptr_t ActorArray = driver.read2<uintptr_t>(PersistentLevel + ACTOR_ARRAY);
		int ActorCount = driver.read2<int>(PersistentLevel + ACTOR_COUNT);
		enemy_array = SDK::GetEnemyArray(ActorArray, ActorCount);
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	}
}






inline LONG WINAPI SimplestCrashHandler(EXCEPTION_POINTERS* ExceptionInfo)
{
	if (ExceptionInfo && ExceptionInfo->ExceptionRecord)
		Log(L"[!!] Crash at addr 0x" << ExceptionInfo->ExceptionRecord->ExceptionAddress << L" 0x" << std::hex << ExceptionInfo->ExceptionRecord->ExceptionCode << std::endl);
	else
		Log(L"[!!] Crash" << std::endl);

	if (iqvw64e_device_handle)
		intel_driver::Unload(iqvw64e_device_handle);

	return EXCEPTION_EXECUTE_HANDLER;
}
inline bool callbackExample(ULONG64* param1, ULONG64* param2, ULONG64 allocationPtr, ULONG64 allocationSize, ULONG64 mdlptr) {
	UNREFERENCED_PARAMETER(param1);
	UNREFERENCED_PARAMETER(param2);
	UNREFERENCED_PARAMETER(allocationPtr);
	UNREFERENCED_PARAMETER(allocationSize);
	UNREFERENCED_PARAMETER(mdlptr);
	Log("[+] Callback example called" << std::endl);
	return true;
}
inline void LoadDriver()
{
	system(skCrypt("TASKKILL /F /IM VALORANT-Win64-Shipping.exe >NUL 2>&1"));
	iqvw64e_device_handle = intel_driver::Load();

	NTSTATUS exitCode = 0;
	if (!kdmapper::MapDriver(iqvw64e_device_handle, raw_image.data(), 0, 0, false, true, true, false, callbackExample, &exitCode)) {
		Log(L"[-] Failed to map" << std::endl);
		intel_driver::Unload(iqvw64e_device_handle);
	}

	if (!intel_driver::Unload(iqvw64e_device_handle)) {
		Log(L"[-] Warning failed to fully unload vulnerable driver " << std::endl);
	}
	Log(L"[+] success" << std::endl);
}




int cheat()
{
	if (!driver.init())
	{
		printf(skCrypt("[>] dr1ver not found...\n[>] dr1ver loading...\n"));
		LoadDriver();
	}
	printf(skCrypt("[>] dr1ver founded...\n[>] cheat start1ng...\n"));
	HWND Entryhwnd = NULL;
	while (Entryhwnd == NULL)
	{
		printf(skCrypt("[>] Wa1t1ng for Valorant...\n"));
		Sleep(1);
		Vars::gPid = SDK::GetVALORANTPID();
		printf(skCrypt("[>] PID: %d\n"), Vars::gPid);
		Entryhwnd = get_process_wnd(Vars::gPid);
		Sleep(1);
	}
	driver.attach(Vars::gPid);
	setup_window();
	init_wndparams(Vars::myWnd);
	Vars::gBase = driver.get_guarded_base();
	driver.VirtualAddress = driver.get_guarded_base();
	if (!Vars::gBase) { printf(skCrypt("[>] Couldn't get base address!\n")); return 0; }
	printf(skCrypt("[>] Guarded Base: %p\n"), Vars::gBase);
	CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)cache, nullptr, NULL, nullptr);
	static RECT old_rc;
	ZeroMemory(&Vars::message, sizeof(MSG));
	while (Vars::message.message != WM_QUIT)
	{
		if (PeekMessage(&Vars::message, Vars::myWnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&Vars::message);
			DispatchMessage(&Vars::message);
		}

		HWND hwnd_active = GetForegroundWindow();
		if (GetAsyncKeyState(VK_INSERT) & 1)
			settings::show_menu = !settings::show_menu;


		if (hwnd_active == Vars::gameWnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Vars::myWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(Vars::gameWnd, &rc);
		ClientToScreen(Vars::gameWnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;
		
		UI::style();
		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = Vars::gameWnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(0x1)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom) {

			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			Vars::pParams.BackBufferWidth = Width;
			Vars::pParams.BackBufferHeight = Height;
			SetWindowPos(Vars::myWnd, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			Vars::pDevice->Reset(&Vars::pParams);
		}
		UI::render();
		std::thread(aimbot).detach();
		Sleep(10);
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	if (Vars::pDevice != NULL) {
		Vars::pDevice->EndScene();
		Vars::pDevice->Release();
	}
	
	if (Vars::pObject != NULL) 
		Vars::pObject->Release();
	
	
	DestroyWindow(Vars::myWnd);
	return Vars::message.wParam;
}



void check1()
{
	while (true)
	{
		if (settings::streamproof_enabled)
		{
			wndhide::hide_window(GetCurrentProcessId(), (Vars::myWnd), true);
			wndhide::hide_window(GetCurrentProcessId(), GetConsoleWindow(), true);
		}
		else
		{
			wndhide::hide_window(GetCurrentProcessId(), (Vars::myWnd), false);
			wndhide::hide_window(GetCurrentProcessId(), GetConsoleWindow(), false);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1900));
	}
}


int main()
{
	start: CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)check1, nullptr, NULL, nullptr);
	cheat();
}


