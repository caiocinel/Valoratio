#include "ESP.h"

void ESP::render() {

	std::vector<EnemyPtr> actor = enemy_array;
	printf("Teste 1");
	if (actor.empty()) {
		printf("Teste 2");
		return;
	}
	for (int i = 0; i < actor.size(); i++)
	{
		printf("Teste 3");
		EnemyPtr enemy = actor[i];
		printf("%i", enemy.bone_count);
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
					CustomImGui::DrawCorneredBox(vBaseBoneOut2.x - BoxWidth / 2 + 1, vHeadBoneOut2.y, BoxWidth, BoxHeight, ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])), 2);
				}
				if (settings::box_type == 1)
				{
					CustomImGui::DrawNormalBox(vBaseBoneOut2.x - (BoxWidth / 2), vHeadBoneOut2.y, BoxWidth, BoxHeight, 1, ImGui::ColorConvertFloat4ToU32(ImVec4(settings::box_color[0], settings::box_color[1], settings::box_color[2], settings::box_color[3])));
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
					CustomImGui::DrawLine(ImVec2(g_width / 2, g_height), ImVec2(vBaseBoneOut.x, vBaseBoneOut.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::snapline_color[0], settings::snapline_color[1], settings::snapline_color[2], settings::snapline_color[3])), 1);
				}
				if (settings::line_type == 1)
				{
					CustomImGui::DrawLine(ImVec2(g_width / 2, g_height - 1080), ImVec2(vHeadBoneOut.x, vHeadBoneOut.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::snapline_color[0], settings::snapline_color[1], settings::snapline_color[2], settings::snapline_color[3])), 1);
				}
				if (settings::line_type == 2)
				{
					CustomImGui::DrawLine(ImVec2(g_width / 2, g_height / 2), ImVec2(vBaseBoneOut.x, vBaseBoneOut.y), ImGui::ColorConvertFloat4ToU32(ImVec4(settings::snapline_color[0], settings::snapline_color[1], settings::snapline_color[2], settings::snapline_color[3])), 1);
				}
			}
			if (settings::distance)
			{
				char dist[64];
				sprintf_s(dist, skCrypt("[%.fm]"), distance);
				RGBA col = { settings::distance_color[0], settings::distance_color[1], settings::distance_color[2], settings::distance_color[3] };
				CustomImGui::DrawString(14, vHeadBoneOut.x - 5, vHeadBoneOut.y - 13, &col, true, false, dist);
			}
			if (settings::healthbar)
			{
				CustomImGui::DrawLeftProgressBar(vBaseBoneOut2.x - 8, vHeadBoneOut2.y, BoxWidth, BoxHeight, 5, Health);
			}
		}
	}
}