#pragma once
#include <string>
#include "const.h";

namespace UI {
	void render();
	void drawMenu();
	void style();
};

namespace CustomImGui {		
	void Checkbox(const char* __label__, bool* __value__);
	void Slider(const char* __label__, float __min__, float __max__, float* __value__, float __width__);
	void Picker(const char* label, float* value);
	void HotkeyButton(int aimkey, void* changekey, int status);
	void ChangeKey(void* blank);
};