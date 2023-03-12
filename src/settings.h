#pragma once
#include "struct.h"
#include "thirdparty/skCrypt.h"
inline uintptr_t g_pid;
inline uintptr_t g_base;
static inline char* memdup(const char* s, size_t n)
{
	char* t = (char*)malloc(n);
	memcpy(t, s, n);
	return t;
}
#define _memdup(object) memdup(object, sizeof(object))
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
	inline const char* box[] = { _memdup(skCrypt("Corner Box")), _memdup(skCrypt("Normal Box")), _memdup(skCrypt("3D Box"))};
	inline const char* line[] = { _memdup(skCrypt("Middle Down")), _memdup(skCrypt("Middle Top")), _memdup(skCrypt("Crosshair"))};
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
	inline const char* hitbox2[] = { _memdup(skCrypt("Head")), _memdup(skCrypt("Neck")), _memdup(skCrypt("Body"))};
}