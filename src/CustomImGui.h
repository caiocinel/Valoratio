#pragma once
#include "struct.h"
#include <d3dx9.h>
#include <d3d9types.h>
#include <string>
#include "thirdparty/imgui/imgui.h";
#include "thirdparty/imgui/imgui_impl_dx9.h";
#include "thirdparty/imgui/imgui_impl_win32.h";
#include "const.h";
#include "StrConvert.h";

namespace CustomImGui {
	void Checkbox(const char* __label__, bool* __value__);
	void Slider(const char* __label__, float __min__, float __max__, float* __value__, float __width__);
	void Picker(const char* label, float* value);
	void HotkeyButton(int aimkey, void* changekey, int status);
	void ChangeKey(void* blank);
	void DrawFilledRect(int x, int y, int w, int h, RGBA* color);
	void DrawFilledRect2(int x, int y, int w, int h, ImColor color);
	void DrawNormalBox(int x, int y, int w, int h, int borderPx, ImColor color);
	void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness);
	auto DrawLine(const ImVec2& x, const ImVec2 y, ImU32 color, const FLOAT width) -> void;
	auto Draw2DBox(float x, float y, float w, float h, ImColor color) -> void;
	auto RectFilled(float x, float y, float x1, float y1, ImColor color, float rounding, int rounding_corners_flags) -> void;
	auto DrawHealthBar(float x, float y, float w, float h, int phealth, bool Outlined) -> void;
	void DrawCircleFilled(int x, int y, int radius, RGBA* color, float segments);
	void DrawCircle(int x, int y, int radius, RGBA* color, float segments);
	void DrawLString(float fontSize, int x, int y, ImU32 color, bool bCenter, bool stroke, const char* pText, ...);
	void DrawString(float fontSize, int x, int y, RGBA* color, bool bCenter, bool stroke, const char* pText, ...);
	void DrawLeftProgressBar(int x, int y, int w, int h, int thick, int m_health);
};