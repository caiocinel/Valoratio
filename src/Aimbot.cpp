#include "Aimbot.h"

void Aimbot::run()
{
	try
	{
		FMinimalViewInfo2 camera = driver.read<FMinimalViewInfo2>(gcameramanager + 0x1FE0 + 0x10);
		int hitboxid;
		float aimfov = settings::fov;
		int dwIndex = SDK::ActorLoop(&aimfov);
		if (dwIndex < 0) return;
		FVector pLocalCameraRot = driver.read<FVector>(glocalplayercontroller + CAMERA_ROT);
		if (settings::hitbox == 0)
			hitboxid = 8;
		else if (settings::hitbox == 1)
			hitboxid = 7;
		else if (settings::hitbox == 2)
			hitboxid = 5;
		if (settings::aimbot)
		{
			if (GetAsyncKeyState(settings::aimkey))
			{
				EnemyPtr enemy = enemy_array[dwIndex];
				FVector neck_position = SDK::GetBone2(enemy.mesh_ptr, hitboxid);
				FVector root_position = driver.read<FVector>(enemy.root_component_ptr + ROOT_POS);
				if (neck_position.z <= root_position.z)
				{
					return;
				}
				FVector localView = driver.read<FVector>(glocalplayercontroller + CONTROL_ROT);
				FVector vecCaclculatedAngles = SDK::fhgfsdhkfshdghfsd205(camera.Location, neck_position);
				FVector angleEx = SDK::CaadadalcAngle(camera.Location, neck_position);
				FVector fin = FVector(vecCaclculatedAngles.y, angleEx.y, 0);
				if (settings::rcs) {
					FVector delta = fin - localView;
					FVector TargetAngle = localView + delta;
					SDK::Clamp(TargetAngle);
					SDK::RCS(TargetAngle, camera.Rotation, settings::smooth);
					float temp = SDK::GetFov(pLocalCameraRot, vecCaclculatedAngles);
				}
				else {
					FVector delta = fin - localView;
					SDK::NormalizeAngles(delta);
					FVector TargetAngle = localView + (delta / settings::smooth);
					SDK::NormalizeAngles(TargetAngle);
					driver.write<FVector>(glocalplayercontroller + CONTROL_ROT, TargetAngle);
					float temp = SDK::GetFov(pLocalCameraRot, vecCaclculatedAngles);
				}
			}
		}

		if (GetAsyncKeyState(VK_LBUTTON) && settings::silentaim == true)
		{
			EnemyPtr enemy = enemy_array[dwIndex];

			FVector oldpos;
			FVector neck_position = SDK::GetBone2(enemy.mesh_ptr, 8);
			FVector localView = driver.read<FVector>(glocalplayercontroller + CONTROL_ROT);
			FVector vecCaclculatedAngles = SDK::fhgfsdhkfshdghfsd205(camera.Location, neck_position);
			FVector angleEx = SDK::CaadadalcAngle(camera.Location, neck_position);
			FVector fin = FVector(vecCaclculatedAngles.y, angleEx.y, 0);
			FVector delta = fin - localView;
			SDK::NormalizeAngles(delta);
			FVector TargetAngle = localView + (delta);
			SDK::NormalizeAngles(TargetAngle);
			oldpos = driver.read<FVector>(glocalplayercontroller + CONTROL_ROT);
			driver.write<FVector>(glocalplayercontroller + CONTROL_ROT, TargetAngle);
			Sleep(15);
			driver.write<FVector>(glocalplayercontroller + CONTROL_ROT, oldpos);
			Sleep(50);
		}
	}
	catch (std::exception e)
	{
	}
}