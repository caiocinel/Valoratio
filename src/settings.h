#pragma once

namespace settings{
	inline bool show_menu;
	inline bool esp_enabled = true;
	inline bool bone_esp = true; static float bone_color[4] = {255, 255, 255, 255};
	inline bool headcircle = true; static float headcircle_color[4] = { 255, 255, 255, 255 };
	inline bool box_esp = true; static float box_color[4] = { 255, 255, 255, 255 };
	inline bool snapline = true; static float snapline_color[4] = { 255, 255, 255, 255 };
	inline bool distance = true; static float distance_color[4] = { 255.0f, 255.0f, 255.0f, 255.0f };
	inline bool healthbar = true;
	inline bool glow = true;
	inline int box_type, line_type;
	inline const char* box[] = { "Corner Box", "Normal Box", "3D Box"};
	inline const char* line[] = { "Middle Down", "Middle Top", "Crosshair"};
	inline int aimkey;
	inline bool aimbot = true;
	inline bool silentaim = false;
	inline bool visiblecheck = true;
	inline bool streamproof_enabled = false;

	inline bool teamcheck;
	inline bool rcs;
	inline bool autoshoot = false;
	inline float fov = 60;
	inline float smooth = 1;
	inline int hitbox;
	inline const char* hitbox2[] = { "Head", "Neck", "Body"};
}