#include <d3dx9.h>
#include <d3d9types.h>
#include "settings.h";
#include "thirdparty/imgui/imgui.h";
#include "thirdparty/imgui/imgui_impl_dx9.h";
#include "thirdparty/imgui/imgui_impl_win32.h";
#include "vars.h";
#include "ui.h";
#include "ESP.h"

void UI::render() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (settings::esp_enabled)
		ESP::render();
	
	
		

	UI::drawMenu();
	if (settings::aimbot)
	{
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(Vars::screenCenterX, Vars::screenCenterY), settings::fov, IM_COL32_WHITE, 10000, 1);
	}
	ImGui::EndFrame();
	Vars::pDevice->SetRenderState(D3DRS_ZENABLE, false);
	Vars::pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	Vars::pDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	Vars::pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (Vars::pDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		Vars::pDevice->EndScene();
	}

	HRESULT result = Vars::pDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && Vars::pDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		Vars::pDevice->Reset(&Vars::d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}

void UI::drawMenu(){
	if (settings::show_menu)
	{
		ImGui::Begin("Valoratio", 0, ImGuiWindowFlags_NoCollapse);
		{
			ImGui::Columns(2);
			ImGui::SetColumnOffset(1, 120);
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();

			ImGui::Spacing();
			if (ImGui::Button("Aimbot", ImVec2(100, 40)))
				Vars::activeTab = 1;

			ImGui::Spacing();
			if (ImGui::Button("Visuals", ImVec2(100, 40)))
				Vars::activeTab = 2;
			ImGui::Spacing();
			ImGui::Spacing();
			CustomImGui::Checkbox("StreamProof", &settings::streamproof_enabled);

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


			ImGui::NextColumn();
			{
				if (Vars::activeTab == 1)
				{
					ImGui::Text("Aim Settings");
					ImGui::Separator();
					ImGui::Spacing();
					CustomImGui::Checkbox("Aimbot", &settings::aimbot);
					CustomImGui::Slider(("Fov"), 0, 2500, &settings::fov, ImGui::GetContentRegionAvail().x / 3);
					ImGui::SliderFloat("Smooth", &settings::smooth, 1, 30);
					CustomImGui::Checkbox("Visible Check", &settings::visiblecheck);
					CustomImGui::Checkbox("Team Check", &settings::teamcheck);
					CustomImGui::Checkbox("Recoil Control", &settings::rcs);
					CustomImGui::Checkbox("Silent Aim", &settings::silentaim);
					ImGui::Combo("Hitbox", &settings::hitbox, settings::hitbox2, IM_ARRAYSIZE(settings::hitbox2));
					CustomImGui::HotkeyButton(settings::aimkey, CustomImGui::ChangeKey, Vars::keystatus);
					ImGui::SameLine();
					ImGui::Text(" - Aim key");
				}
				if (Vars::activeTab == 2)
				{
					ImGui::Text("Visual Settings");
					ImGui::Separator();
					ImGui::Spacing();
					CustomImGui::Checkbox("Enable ESP", &settings::esp_enabled);
					CustomImGui::Checkbox("Bone ESP", &settings::bone_esp);
					CustomImGui::Checkbox("Head ESP", &settings::headcircle);
					CustomImGui::Checkbox("Box ESP", &settings::box_esp);
					ImGui::Combo("Box Type", &settings::box_type, settings::box, IM_ARRAYSIZE(settings::box));
					CustomImGui::Checkbox("Snapline ESP", &settings::snapline);
					ImGui::Combo("Snapline Type", &settings::line_type, settings::line, IM_ARRAYSIZE(settings::line));
					CustomImGui::Checkbox("Healthbar ESP", &settings::healthbar);
					CustomImGui::Checkbox("Distance ESP", &settings::distance);
				}

			}
		}
		ImGui::End();
	}
}

void UI::style() {
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 1.f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 1.f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 1.f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 1.f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 1.f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 1.f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 1.f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 1.f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 1.f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 1.f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 1.f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 1.f, 1.f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 1.f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 1.f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 1.f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 1.f);

	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(8.00f, 8.00f);
	style.FramePadding = ImVec2(5.00f, 2.00f);
	style.ItemSpacing = ImVec2(6.00f, 6.00f);
	style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 25;
	style.ScrollbarSize = 15;
	style.GrabMinSize = 10;
	style.Alpha = 1.0f;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	style.FrameBorderSize = 1;
	style.WindowRounding = 7;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.GrabRounding = 3;
}

void CustomImGui::Checkbox(const char* __label__, bool* __value__)
{
	ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 6, ImGui::GetCursorPosY() + 6));
	ImGui::Checkbox(__label__, __value__);
	ImGui::Spacing();
};

void CustomImGui::Slider(const char* __label__, float __min__, float __max__, float* __value__, float __width__)
{
	ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 6, ImGui::GetCursorPosY() + 6));
	ImGui::PushID("##CustomSlider_");
	ImGui::PushItemWidth(__width__);
	ImGui::SliderFloat(__label__, __value__, __min__, __max__, __label__);
	ImGui::PopItemWidth();
	ImGui::PopID();
	ImGui::Spacing();
};

void CustomImGui::Picker(const char* label, float* value)
{
	ImGui::ColorEdit4(label, value, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
	ImGui::Spacing();
};

void CustomImGui::HotkeyButton(int aimkey, void* changekey, int status)
{
	const char* preview_value = NULL;
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(Const::keyNames)) {
		const char* const* items = (const char* const*)Const::keyNames;
		if (preview_value)
			preview_value = items[aimkey];
	}

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = ("Select Key");
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = ("Press key to bind");
	}
	if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20)))
	{
		if (status == 0)
		{
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
		}
	}
}

void CustomImGui::ChangeKey(void* blank)
{
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				settings::aimkey = i;
				return;
			}
		}
	}
}