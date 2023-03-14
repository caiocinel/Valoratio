#include "main.h"
#include "Tests.h"

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
		uintptr_t Inv = driver.read2<uintptr_t>(glocalpawn + INVENTORY);
		uintptr_t CurrentWeapon = driver.read2<uintptr_t>(Inv + CURRENT_WEAPON);		
		int WeaponId = driver.read2<int>(CurrentWeapon + 0x18);
		printf("ID: %i\n", WeaponId);
		uintptr_t LocalTeamComponent = driver.read2<uintptr_t>(LocalPlayerState + TEAM_COMP);
		glocalteamid = driver.read2<int>(LocalTeamComponent + TEAM_ID);
		gcameramanager = driver.read2<uintptr_t>(glocalplayercontroller + CAMERA_MANAGER);
		uintptr_t ActorArray = driver.read2<uintptr_t>(PersistentLevel + ACTOR_ARRAY);
		int ActorCount = driver.read2<int>(PersistentLevel + ACTOR_COUNT);
		enemy_array = SDK::GetEnemyArray(ActorArray, ActorCount);
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	}
}

inline void LoadDriver()
{
	system(skCrypt("TASKKILL /F /IM VALORANT-Win64-Shipping.exe >NUL 2>&1"));
	Vars::driverHandle = intel_driver::Load();

	NTSTATUS exitCode = 0;
	if (!kdmapper::MapDriver(Vars::driverHandle, raw_image.data(), 0, 0, false, true, true, false, [](ULONG64* param1, ULONG64* param2, ULONG64 allocationPtr, ULONG64 allocationSize, ULONG64 mdlptr) {
		UNREFERENCED_PARAMETER(param1);
		UNREFERENCED_PARAMETER(param2);
		UNREFERENCED_PARAMETER(allocationPtr);
		UNREFERENCED_PARAMETER(allocationSize);
		UNREFERENCED_PARAMETER(mdlptr);
		Log("[+] Callback example called" << std::endl);
		return true;
	}, &exitCode)) {
		Log(L"[-] Failed to map" << std::endl);
		intel_driver::Unload(Vars::driverHandle);
	}

	if (!intel_driver::Unload(Vars::driverHandle)) 
		Log(L"[-] Warning failed to fully unload vulnerable driver " << std::endl);
	Log(L"[+] success" << std::endl);
}

int main()
{
	if (!driver.init())
		LoadDriver();
	
	HWND Entryhwnd = NULL;
	while (Entryhwnd == NULL)
	{
		printf(skCrypt("[>] Wa1t1ng for Valorant...\n"));
		Sleep(1);
		Vars::gPid = SDK::GetVALORANTPID();
		printf(skCrypt("[>] PID: %d\n"), Vars::gPid);
		Entryhwnd = Overlay::getProcessWnd(Vars::gPid);
		Sleep(10000);
	}
	driver.attach(Vars::gPid);
	Overlay::setupWindow();
	Overlay::initWnd(Vars::myWnd);
	Vars::gBase = driver.get_guarded_base();
	driver.VirtualAddress = driver.get_guarded_base();
	if (!Vars::gBase){
		printf(skCrypt("[>] Couldn't get base address!\n")); 
		return 0; 
	}
	
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

			Overlay::Width = rc.right;
			Overlay::Height = rc.bottom;
			g_width = GetSystemMetrics(SM_CXSCREEN);
			g_height = GetSystemMetrics(SM_CYSCREEN);

			Vars::pParams.BackBufferWidth = Overlay::Width;
			Vars::pParams.BackBufferHeight = Overlay::Height;
			SetWindowPos(Vars::myWnd, (HWND)0, xy.x, xy.y, Overlay::Width, Overlay::Height, SWP_NOREDRAW);
			Vars::pDevice->Reset(&Vars::pParams);
		}
		UI::render();
		Tests::run();
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


