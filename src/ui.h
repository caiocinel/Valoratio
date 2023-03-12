#pragma once
#include <string>
#include "const.h";
#include <d3dx9.h>
#include <d3d9types.h>
#include "settings.h";
#include "thirdparty/imgui/imgui.h";
#include "thirdparty/imgui/imgui_impl_dx9.h";
#include "thirdparty/imgui/imgui_impl_win32.h";
#include "Vars.h";
#include "CustomImGui.h";
#include "ESP.h"

namespace UI {
	void render();
	void drawMenu();
	void style();
};