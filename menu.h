#pragma once
#include "overlay.h"
#include <string>
#include <Windows.h>
#include "settings.h"
int realkey;
int keystatus;
bool GetKey(int key)
{
	realkey = key;
	return true;
}
void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				settings::aimkey = i;
				keystatus = 0;
				return;
			}
		}
	}
}
static const char* keyNames[] =
{
	"",
	"Left Mouse",
	"Right Mouse",
	"Cancel",
	"Middle Mouse",
	"Mouse 5",
	"Mouse 4",
	"",
	"Backspace",
	"Tab",
	"",
	"",
	"Clear",
	"Enter",
	"",
	"",
	"Shift",
	"Control",
	"Alt",
	"Pause",
	"Caps",
	"",
	"",
	"",
	"",
	"",
	"",
	"Escape",
	"",
	"",
	"",
	"",
	"Space",
	"Page Up",
	"Page Down",
	"End",
	"Home",
	"Left",
	"Up",
	"Right",
	"Down",
	"",
	"",
	"",
	"Print",
	"Insert",
	"Delete",
	"",
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"X",
	"Y",
	"Z",
	"",
	"",
	"",
	"",
	"",
	"Numpad 0",
	"Numpad 1",
	"Numpad 2",
	"Numpad 3",
	"Numpad 4",
	"Numpad 5",
	"Numpad 6",
	"Numpad 7",
	"Numpad 8",
	"Numpad 9",
	"Multiply",
	"Add",
	"",
	"Subtract",
	"Decimal",
	"Divide",
	"F1",
	"F2",
	"F3",
	"F4",
	"F5",
	"F6",
	"F7",
	"F8",
	"F9",
	"F10",
	"F11",
	"F12",
};
static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}
void HotkeyButton(int aimkey, void* changekey, int status)
{
	const char* preview_value = NULL;
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
		Items_ArrayGetter(keyNames, aimkey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = skCrypt("Select Key");
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = skCrypt("Press key to bind");
	}
	if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20)))
	{
		if (status == 0)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}

namespace Variables {
	int ActiveTab = 1;
}

auto Checkbox = [&](const char* __label__, bool* __value__)
{
	ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 6, ImGui::GetCursorPosY() + 6));
	ImGui::Checkbox(__label__, __value__);
	ImGui::Spacing();
};

auto Slider = [&](const char* __label__, float __min__, float __max__, float* __value__, float __width__)
{
	ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 6, ImGui::GetCursorPosY() + 6));
	ImGui::PushID(("##CustomSlider_"));
	ImGui::PushItemWidth(__width__);
	ImGui::SliderFloat(__label__, __value__, __min__, __max__, __label__);
	ImGui::PopItemWidth();
	ImGui::PopID();
	ImGui::Spacing();
};

auto Picker = [&](const char* label, float* value)
{
	ImGui::ColorEdit4(label, value, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
	ImGui::Spacing();
};

void draw_menu()
{
	if (settings::show_menu)
	{
		/*	Style();
			ImGui::SetNextWindowSize(ImVec2(415, 474));
			ImGui::Begin(skCrypt("Spiro Development - Valorant V1"), 0, ImGuiWindowFlags_NoCollapse );
			Checkbox(skCrypt("Enable ESP"), &settings::esp_enabled);
			Checkbox(skCrypt("Bone ESP"), &settings::bone_esp);// ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Bone"), settings::bone_color );
			Checkbox(skCrypt("Head ESP"), &settings::headcircle); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Head"), settings::headcircle_color );
			Checkbox(skCrypt("Box ESP"), &settings::box_esp); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Box"), settings::box_color );
			ImGui::Combo(skCrypt("Box Type"), &settings::box_type, settings::box, IM_ARRAYSIZE(settings::box));
			Checkbox(skCrypt("Snapline ESP"), &settings::snapline);// ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Snapline"), settings::snapline_color );
			ImGui::Combo(skCrypt("Snapline Type"), &settings::line_type, settings::line, IM_ARRAYSIZE(settings::line));
			Checkbox(skCrypt("Healthbar ESP"), &settings::healthbar);
			Checkbox(skCrypt("Distance ESP"), &settings::distance); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Distance"), settings::distance_color);
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();
			Checkbox(skCrypt("Aimbot"), &settings::aimbot);
			ImGui::SliderFloat(skCrypt("Fov"), &settings::fov, 1, 360);
			ImGui::SliderFloat(skCrypt("Smooth"), &settings::smooth, 1, 30);
			Checkbox(skCrypt("Visible Check"), &settings::visiblecheck);
			Checkbox(skCrypt("Team Check"), &settings::teamcheck);
			Checkbox(skCrypt("Recoil Control"), &settings::rcs);
			Checkbox(skCrypt("Silent Aim"), &settings::silentaim);
			ImGui::Combo(skCrypt("Hitbox"), &settings::hitbox, settings::hitbox2, IM_ARRAYSIZE(settings::hitbox2));
			HotkeyButton(settings::aimkey, ChangeKey, keystatus);
			ImGui::End();  */

			/*	DWORD window_flags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar; //ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar
				ImGui::SetNextWindowSize(ImVec2(415, 500));
				ImGui::Begin("Valorant", 0, window_flags);
			//	ImGui::SetNextWindowSize(ImVec2(1000, 1000));
				ImGui::Text(("Gucci")); ImGui::SameLine(0, 1.5);
				ImGui::TextColored(ImColor(204, 0, 255, 255), ("Cheats"));  ImGui::SameLine(0, 1.5);
				ImGui::TextColored(ImColor(255, 0, 0, 255), (" - Valorant"));

				ImGui::Separator();



				Checkbox(skCrypt("Enable ESP"), &settings::esp_enabled);
				Checkbox(skCrypt("Bone ESP"), &settings::bone_esp);// ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Bone"), settings::bone_color );
				Checkbox(skCrypt("Head ESP"), &settings::headcircle); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Head"), settings::headcircle_color );
				Checkbox(skCrypt("Box ESP"), &settings::box_esp); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Box"), settings::box_color );
				ImGui::Combo(skCrypt("Box Type"), &settings::box_type, settings::box, IM_ARRAYSIZE(settings::box));
				Checkbox(skCrypt("Snapline ESP"), &settings::snapline);// ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Snapline"), settings::snapline_color );
				ImGui::Combo(skCrypt("Snapline Type"), &settings::line_type, settings::line, IM_ARRAYSIZE(settings::line));
				Checkbox(skCrypt("Healthbar ESP"), &settings::healthbar);
				Checkbox(skCrypt("Distance ESP"), &settings::distance); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Distance"), settings::distance_color);
				ImGui::Separator();
				Checkbox(skCrypt("Aimbot"), &settings::aimbot);
		//		Slider(skCrypt("Fov"), &settings::fov, 1, 360);
				Slider(("Fov"), 0, 2500, &settings::fov, ImGui::GetContentRegionAvail().x / 3);
				ImGui::SliderFloat(skCrypt("Smooth"), &settings::smooth, 1, 30);
				Checkbox(skCrypt("Visible Check"), &settings::visiblecheck);
				Checkbox(skCrypt("Team Check"), &settings::teamcheck);
				Checkbox(skCrypt("Recoil Control"), &settings::rcs);
				Checkbox(skCrypt("Silent Aim"), &settings::silentaim);
				ImGui::Combo(skCrypt("Hitbox"), &settings::hitbox, settings::hitbox2, IM_ARRAYSIZE(settings::hitbox2));
				HotkeyButton(settings::aimkey, ChangeKey, keystatus);
				ImGui::Text("Test"); */
				// gucci menu ^^

	   //		DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

	   //		RECT screen_rect;
	   //		GetWindowRect(GetDesktopWindow(), &screen_rect);

		Style();

		ImGui::Begin("                  H3XTCH - V4L0R4NT", 0, ImGuiWindowFlags_NoCollapse);
		{



			ImGui::Columns(2);
			ImGui::SetColumnOffset(1, 120);
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();

			ImGui::Spacing();
			if (ImGui::Button("Aimbot", ImVec2(100, 40)))
				Variables::ActiveTab = 1;

			ImGui::Spacing();
			if (ImGui::Button("Visuals", ImVec2(100, 40)))
				Variables::ActiveTab = 2;
			ImGui::Spacing();
			ImGui::Spacing();
			Checkbox(skCrypt("StreamProof"), &settings::streamproof_enabled);

			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			//	ImGui::Text("   Made By");
			ImGui::Text("www.hextch.com");
	

			ImGui::NextColumn();
			{
				if (Variables::ActiveTab == 1)
				{
					ImGui::Text("Aim Settings");
					ImGui::Separator();
					ImGui::Spacing();
					Checkbox(skCrypt("Aimbot"), &settings::aimbot);
					//		Slider(skCrypt("Fov"), &settings::fov, 1, 360);
					Slider(("Fov"), 0, 2500, &settings::fov, ImGui::GetContentRegionAvail().x / 3);
					ImGui::SliderFloat(skCrypt("Smooth"), &settings::smooth, 1, 30);
					Checkbox(skCrypt("Visible Check"), &settings::visiblecheck);
					Checkbox(skCrypt("Team Check"), &settings::teamcheck);
					Checkbox(skCrypt("Recoil Control"), &settings::rcs);
					Checkbox(skCrypt("Silent Aim"), &settings::silentaim);
					ImGui::Combo(skCrypt("Hitbox"), &settings::hitbox, settings::hitbox2, IM_ARRAYSIZE(settings::hitbox2));
					HotkeyButton(settings::aimkey, ChangeKey, keystatus);
					ImGui::SameLine();
					ImGui::Text(" - Aim key");
				}
				if (Variables::ActiveTab == 2)
				{
					ImGui::Text("Visual Settings");
					ImGui::Separator();
					ImGui::Spacing();
					Checkbox(skCrypt("Enable ESP"), &settings::esp_enabled);
					Checkbox(skCrypt("Bone ESP"), &settings::bone_esp);// ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Bone"), settings::bone_color );
					Checkbox(skCrypt("Head ESP"), &settings::headcircle); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Head"), settings::headcircle_color );
					Checkbox(skCrypt("Box ESP"), &settings::box_esp); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Box"), settings::box_color );
					ImGui::Combo(skCrypt("Box Type"), &settings::box_type, settings::box, IM_ARRAYSIZE(settings::box));
					Checkbox(skCrypt("Snapline ESP"), &settings::snapline);// ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Snapline"), settings::snapline_color );
					ImGui::Combo(skCrypt("Snapline Type"), &settings::line_type, settings::line, IM_ARRAYSIZE(settings::line));
					Checkbox(skCrypt("Healthbar ESP"), &settings::healthbar);
					Checkbox(skCrypt("Distance ESP"), &settings::distance); //ImGui::SameLine(); ImGui::ColorEdit4(skCrypt("Distance"), settings::distance_color);
				}

			}
		}
		ImGui::End();



	}
}