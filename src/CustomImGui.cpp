#include "CustomImGui.h"

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
				return;
			}
		}
	}
}

void CustomImGui::DrawFilledRect(int x, int y, int w, int h, RGBA* color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), 0, 0);
}

void CustomImGui::DrawFilledRect2(int x, int y, int w, int h, ImColor color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
}

void CustomImGui::DrawNormalBox(int x, int y, int w, int h, int borderPx, ImColor color)
{
	DrawFilledRect2(x + borderPx, y, w, borderPx, color);
	DrawFilledRect2(x + w - w + borderPx, y, w, borderPx, color);
	DrawFilledRect2(x, y, borderPx, h, color);
	DrawFilledRect2(x, y + h - h + borderPx * 2, borderPx, h, color);
	DrawFilledRect2(x + borderPx, y + h + borderPx, w, borderPx, color);
	DrawFilledRect2(x + w - w + borderPx, y + h + borderPx, w, borderPx, color);
	DrawFilledRect2(x + w + borderPx, y, borderPx, h, color);
	DrawFilledRect2(x + w + borderPx, y + h - h + borderPx * 2, borderPx, h, color);
}

void CustomImGui::DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness)
{
	float lineW = (W / 3);
	float lineH = (H / 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}
auto CustomImGui::DrawLine(const ImVec2& x, const ImVec2 y, ImU32 color, const FLOAT width) -> void
{
	ImGui::GetOverlayDrawList()->AddLine(x, y, color, width);
}

auto CustomImGui::Draw2DBox(float x, float y, float w, float h, ImColor color) -> void
{
	DrawLine(ImVec2(x, y), ImVec2(x + w, y), color, 1.3f); // top 
	DrawLine(ImVec2(x, y - 1.3f), ImVec2(x, y + h + 1.4f), color, 1.3f); // left
	DrawLine(ImVec2(x + w, y - 1.3f), ImVec2(x + w, y + h + 1.4f), color, 1.3f);  // right
	DrawLine(ImVec2(x, y + h), ImVec2(x + w, y + h), color, 1.3f);   // bottom 
}

auto CustomImGui::RectFilled(float x, float y, float x1, float y1, ImColor color, float rounding, int rounding_corners_flags) -> void
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x1, y1), color, rounding, rounding_corners_flags);
}

auto CustomImGui::DrawHealthBar(float x, float y, float w, float h, int phealth, bool Outlined) -> void
{
	auto vList = ImGui::GetOverlayDrawList();

	int healthValue = max(0, min(phealth, 100));

	ImColor barColor = ImColor
	(
		min(510 * (100 - healthValue) / 100, 255), min(510 * healthValue / 100, 255),
		25,
		255
	);
	if (Outlined)
		vList->AddRect(ImVec2(x - 1, y - 1), ImVec2(x + w + 1, y + h + 1), ImColor(0.f, 0.f, 0.f), 0.0f, 0, 1.0f);

	CustomImGui::RectFilled(x, y, x + w, y + (int)(((float)h / 100.0f) * (float)phealth), barColor, 0.0f, 0);
}

void CustomImGui::DrawCircleFilled(int x, int y, int radius, RGBA* color, float segments)
{
	ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), segments);
}

void CustomImGui::DrawCircle(int x, int y, int radius, RGBA* color, float segments)
{
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), segments);
}

void CustomImGui::DrawLString(float fontSize, int x, int y, ImU32 color, bool bCenter, bool stroke, const char* pText, ...)
{
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = StrConvert::WStringToUTF8(StrConvert::MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 2;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), color, text.c_str());
}

void CustomImGui::DrawString(float fontSize, int x, int y, RGBA* color, bool bCenter, bool stroke, const char* pText, ...)
{
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = StrConvert::WStringToUTF8(StrConvert::MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 4;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), text.c_str());
}
void CustomImGui::DrawLeftProgressBar(int x, int y, int w, int h, int thick, int m_health)
{
	int G = (255 * m_health / 100);
	int R = 255 - G;
	RGBA healthcol = { R, G, 0, 255 };

	CustomImGui::DrawFilledRect(x - (w / 2) - 3, y, thick, (h)*m_health / 100, &healthcol);
}