#include "sdk.h"
#include "overlay.h"
#include <Windows.h>
#include "thirdparty/wndhide.h"
#include <string>
#include "thirdparty/KdMapper/kdmapper.hpp"
#include "ui.h"


inline HANDLE iqvw64e_device_handle;
int hitbux;

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
	cleanup_d3d();
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


