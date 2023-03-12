#include "sdk.h"
#include "overlay.h"
#include "menu.h"
#include "util.h"
#include <Windows.h>
#include "wndhide.h"
#include "auth.hpp"
#include <string>

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

using namespace KeyAuth;

std::string name = "Valorant Hextch"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "5IBCHtMK3n"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "5ca36b67cdfe9c2ab0b2bf750dcdbfa47623f206d5aa380006fefcb5bbc9d7db"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/"; // change if you're self-hosting

/*
	Video on what ownerid and secret are https://youtu.be/uJ0Umy_C6Fg
	Video on how to add KeyAuth to your own application https://youtu.be/GB4XW_TsHqA
	Video to use Web Loader (control loader from customer panel) https://youtu.be/9-qgmsUUCK4
*/

api KeyAuthApp(name, ownerid, secret, version, url);

void make_hack()
{

	std::vector<EnemyPtr> actor = enemy_array;
	if (actor.empty()) {
		return;
	}
	for (int i = 0; i < actor.size(); i++)
	{
		EnemyPtr enemy = actor[i];
		Vector3 vBaseBone = SDK::GetBone(enemy.mesh_ptr, 0);
		Vector3 vBaseBoneOut = SDK::ProjectWorldToScreen(vBaseBone);
		Vector3 vBaseBoneOut2 = SDK::ProjectWorldToScreen(Vector3(vBaseBone.x, vBaseBone.y, vBaseBone.z - 15));
		Vector3 vHeadBone = SDK::GetBone(enemy.mesh_ptr, 8);
		Vector3 vHeadBoneOut = SDK::ProjectWorldToScreen(Vector3(vHeadBone.x, vHeadBone.y, vHeadBone.z));
		Vector3 vHeadBoneOut2 = SDK::ProjectWorldToScreen(Vector3(vHeadBone.x, vHeadBone.y, vHeadBone.z));
		auto LocalRootComponent = driver.read<uintptr_t>(glocalpawn + ROOT_COMPONENT);
		auto LocalRelativeLocation = driver.read<Vector3>(LocalRootComponent + ROOT_POS);
		auto ActorRelativeLocation = driver.read<Vector3>(enemy.root_component_ptr + ROOT_POS);
		auto distance = LocalRelativeLocation.Distance(ActorRelativeLocation);
		float BoxHeight = abs(vHeadBoneOut.y - vBaseBoneOut.y);
		float BoxWidth = BoxHeight * 0.55;
		auto IsVisible = SDK::IsVisible(enemy.mesh_ptr);
		bool IsDormant = driver.read<bool>(enemy.actor_ptr + DORMANT);
		float Health = driver.read<float>(enemy.damage_handler_ptr + HEALTH);
		auto BoneCount = enemy.bone_count;
		int head_x = vHeadBoneOut.x;
		int head_y = vHeadBoneOut.y;
		int start_x = head_x - 35 / distance;
		int start_y = head_y - 15 / distance;
		int start_x2 = head_x - 35;
		int start_y2 = head_y - 15;
		int hp_x = head_x + 10 / distance;
		int hp_y = head_y + -40 / distance;
		int dis_x = head_x - 50 / distance;
		int dis_y = head_y + -40 / distance;
		int end_x = head_x + 35 / distance;
		int end_y = head_y + 155 / distance;
		if (Health <= 0) continue;
		if (distance < 200)
		{
			if (settings::bone_esp)
			{
				SDK::DrawBones(enemy);
			}
			if (settings::headcircle)
			{
				ImGui::GetOverlayDrawList()->AddCircle(ImVec2(vHeadBoneOut.x, vHeadBoneOut.y), 5, ImGui::ColorConvertFloat4ToU32(ImVec4(settings::headcircle_color[0], settings::headcircle_color[1], settings::headcircle_color[2], settings::headcircle_color[3])), 12, 2);
			}
			if (settings::box_esp)
			{
				if (settings::box_type == 0)
				{
					DrawCorneredBox(vBaseBoneOut2.x - BoxWidth / 2 + 1, vHeadBoneOut2.y, BoxWidth, BoxHeight, ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 2);
				}
				if (settings::box_type == 1)
				{
					DrawNormalBox(vBaseBoneOut2.x - (BoxWidth / 2), vHeadBoneOut2.y, BoxWidth, BoxHeight, 1, ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])));
				}
				if (settings::box_type == 2)
				{
					Vector3 bottom1 = SDK::ProjectWorldToScreen(Vector3(vBaseBone.x + 40, vBaseBone.y - 40, vBaseBone.z));
					Vector3 bottom2 = SDK::ProjectWorldToScreen(Vector3(vBaseBone.x - 40, vBaseBone.y - 40, vBaseBone.z));
					Vector3 bottom3 = SDK::ProjectWorldToScreen(Vector3(vBaseBone.x - 40, vBaseBone.y + 40, vBaseBone.z));
					Vector3 bottom4 = SDK::ProjectWorldToScreen(Vector3(vBaseBone.x + 40, vBaseBone.y + 40, vBaseBone.z));

					Vector3 top1 = SDK::ProjectWorldToScreen(Vector3(vHeadBone.x + 40, vHeadBone.y - 40, vHeadBone.z + 15));
					Vector3 top2 = SDK::ProjectWorldToScreen(Vector3(vHeadBone.x - 40, vHeadBone.y - 40, vHeadBone.z + 15));
					Vector3 top3 = SDK::ProjectWorldToScreen(Vector3(vHeadBone.x - 40, vHeadBone.y + 40, vHeadBone.z + 15));
					Vector3 top4 = SDK::ProjectWorldToScreen(Vector3(vHeadBone.x + 40, vHeadBone.y + 40, vHeadBone.z + 15));

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom3.x, bottom3.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom3.x, bottom3.y), ImVec2(bottom4.x, bottom4.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom4.x, bottom4.y), ImVec2(bottom1.x, bottom1.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);

					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top3.x, top3.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top3.x, top3.y), ImVec2(top4.x, top4.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(top4.x, top4.y), ImVec2(top1.x, top1.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 0.1f);
				}
			}
			if (settings::snapline)
			{
				if (settings::line_type == 0)
				{
					DrawLine(ImVec2(g_width / 2, g_height), ImVec2(vBaseBoneOut.x, vBaseBoneOut.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::snapline_color[0], settings::snapline_color[1], settings::snapline_color[2], settings::snapline_color[3])), 1);
				}
				if (settings::line_type == 1)
				{
					DrawLine(ImVec2(g_width / 2, g_height - 1080), ImVec2(vHeadBoneOut.x, vHeadBoneOut.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::snapline_color[0], settings::snapline_color[1], settings::snapline_color[2], settings::snapline_color[3])), 1);
				}
				if (settings::line_type == 2)
				{
					DrawLine(ImVec2(g_width / 2, g_height / 2), ImVec2(vBaseBoneOut.x, vBaseBoneOut.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::snapline_color[0], settings::snapline_color[1], settings::snapline_color[2], settings::snapline_color[3])), 1);
				}
			}
			if (settings::distance)
			{
				char dist[64];
				sprintf_s(dist, skCrypt("[%.fm]"), distance);
				RGBA col = { settings::distance_color[0], settings::distance_color[1], settings::distance_color[2], settings::distance_color[3] };
				DrawString(14, vHeadBoneOut.x - 5, vHeadBoneOut.y - 13, &col, true, false, dist);
			}
			if (settings::healthbar)
			{
				DrawLeftProgressBar(vBaseBoneOut2.x - 8, vHeadBoneOut2.y, BoxWidth, BoxHeight, 5, Health);
			}
		}
	}
}


void render()
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (GetAsyncKeyState(VK_INSERT) & 1) { settings::show_menu = !settings::show_menu; }

	if (settings::esp_enabled) { make_hack(); }
	draw_menu();
	if (settings::aimbot)
	{
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), settings::fov, IM_COL32_WHITE, 10000, 1);
	}
	if (GetAsyncKeyState(VK_F4) & 1)
	{
		uintptr_t playerstatelocal = driver.read<uintptr_t>(glocalpawn + PLAYER_STATE);
		uintptr_t teamComponent = driver.read<uintptr_t>(playerstatelocal + TEAM_COMP);
		int teamID = driver.read<int>(teamComponent + TEAM_ID);

		teamID = !(bool)teamID;

		driver.write<int>(teamComponent + TEAM_ID, teamID);
	}
	ImGui::EndFrame();
	p_Device->SetRenderState(D3DRS_ZENABLE, false);
	p_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	p_Device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	p_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (p_Device->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		p_Device->EndScene();
	}

	HRESULT result = p_Device->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && p_Device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		p_Device->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}
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
		uintptr_t UWorld = driver.read2<uintptr_t>(g_base + 0x50);
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
#include "KdMapper/kdmapper.hpp"
inline HANDLE iqvw64e_device_handle;

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
	system(skCrypt("TASKKILL /F /IM VALORANT-Win64-Shipping.exe >NUL 2>&1"));
	Sleep(2000);
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
	Abdul::SetPenisRep(WHITE);
	printf("[");
	Abdul::SetPenisRep(GREEN);
	printf("SUCCESS");
	Abdul::SetPenisRep(WHITE);
	printf("] - Key is valid, please wait");
	Sleep(2000);



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
		g_pid = SDK::GetVALORANTPID();
		printf(skCrypt("[>] PID: %d\n"), g_pid);
		Entryhwnd = get_process_wnd(g_pid);
		Sleep(1);
	}
	driver.attach(g_pid);
	setup_window();
	init_wndparams(MyWnd);
	g_base = driver.get_guarded_base();
	driver.VirtualAddress = driver.get_guarded_base();
	if (!g_base) { printf(skCrypt("[>] Couldn't get base address!\n")); return 0; }
	printf(skCrypt("[>] Guarded Base: %p\n"), g_base);
	CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)cache, nullptr, NULL, nullptr);
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));
	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, MyWnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();


		if (hwnd_active == GameWnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(MyWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(GameWnd, &rc);
		ClientToScreen(GameWnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = GameWnd;
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

			p_Params.BackBufferWidth = Width;
			p_Params.BackBufferHeight = Height;
			SetWindowPos(MyWnd, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			p_Device->Reset(&p_Params);
		}
		render();
		std::thread(aimbot).detach();
		Sleep(10);
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	cleanup_d3d();
	DestroyWindow(MyWnd);
	return Message.wParam;
}



void check1()
{
	while (true)
	{
		if (settings::streamproof_enabled)
		{
			wndhide::hide_window(GetCurrentProcessId(), (MyWnd), true);
			wndhide::hide_window(GetCurrentProcessId(), GetConsoleWindow(), true);
		}
		else
		{
			wndhide::hide_window(GetCurrentProcessId(), (MyWnd), false);
			wndhide::hide_window(GetCurrentProcessId(), GetConsoleWindow(), false);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1900));
	}
}


int main()
{

	KeyAuthApp.init();

start:                 CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)check1, nullptr, NULL, nullptr);

	int option;
	std::string username;
	std::string password;
	std::string key;


	Abdul::SetPenisRep(WHITE);
	printf("[");
	Abdul::SetPenisRep(YELLOW);
	printf("KEY");
	Abdul::SetPenisRep(WHITE);
	printf("] - License key: ");
	std::cin >> key;
	KeyAuthApp.license(key);


	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	cheat();
}


