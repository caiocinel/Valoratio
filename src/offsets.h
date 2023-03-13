#pragma once
#define PERSISTENT_LEVEL 0x38 //persistent_level
#define GAME_INSTANCE 0x1A0 //owning_game_instance
#define LOCALPLAYERS_ARRAY 0x40 //local_players
#define PLAYER_CONTROLER 0x38 //player_controller
#define LOCALPLAYERPAWN 0x460 //acknowledged_pawn

#define ROOT_COMPONENT 0x230 //root_component
#define ROOT_POS 0x164 //relative_location
#define ROOT_ROT 0x170 //relative_rotation
#define DAMAGE_HANDLER 0x9e0 //damage_handler
#define CAMERA_CONTROLLER 0x440 //control_rotation
#define CONTROL_ROT 0x440 //control_rotation
#define CAMERA_POS 0x1240
#define CAMERA_ROT 0x124C
#define CAMERA_FOV 0x1258
#define CAMERA_MANAGER 0x478 // player_camera
#define ACTOR_ARRAY 0xA0 //actor_array
#define ACTOR_COUNT ACTOR_ARRAY+0x18
#define ACTOR_ID 0x18 //actor_id
#define UNIQUE_ID 0x38
#define TEAM_COMP 0x628 //team_component
#define TEAM_ID 0xF8 //team_id
#define HEALTH 0x1b0 //current_health
#define DORMANT 0x100 //dormant
#define PLAYER_STATE 0x3F0 //player_state
#define MESH 0x430 //current_mesh
#define COMPONENT 0x250 //component_to_world

#define BONE_ARRAY 0x5c0 //bone_array
#define BONE_COUNT BONE_ARRAY+0x8 //bone_count
#define LAST_SUMBIT_TIME 0x378 //last_sub_time
#define LAST_RENDER_TIME 0x378 + 0x4 
#define INVENTORY 0x980 //0x960 //inventory
#define CURRENT_WEAPON 0x240 // 0x228 //current_equippable

