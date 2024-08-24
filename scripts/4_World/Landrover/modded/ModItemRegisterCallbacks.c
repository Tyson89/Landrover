modded class ModItemRegisterCallbacks
{
    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy(pType, pBehavior);
		
		pType.AddItemInHandsProfileIK("Landrover_Wheel", "dz/anims/workspaces/player/player_main/player_main_heavy.asi",			pBehavior,			"dz/anims/anm/player/ik/vehicles/offroad_02/offroad_02_Wheel.anm");
		pType.AddItemInHandsProfileIK("Landrover_Wheel_Ruined", "dz/anims/workspaces/player/player_main/player_main_heavy.asi",		pBehavior,			"dz/anims/anm/player/ik/vehicles/sedan/sedan_wheeldestroyed.anm");
		pType.AddItemInHandsProfileIK("Landrover_Driver_Door", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", 		pBehavior,			"dz/anims/anm/player/ik/vehicles/v3s/Truck_01_Door_1_1.anm");
		pType.AddItemInHandsProfileIK("Landrover_CoDriver_Door", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", 	pBehavior,			"dz/anims/anm/player/ik/vehicles/v3s/Truck_01_Door_2_1.anm");
		pType.AddItemInHandsProfileIK("Landrover_Hood", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", 			pBehavior,			"dz/anims/anm/player/ik/vehicles/hatchback/hatchback_hood.anm");
		pType.AddItemInHandsProfileIK("Landrover_Trunk", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", 			pBehavior,			"dz/anims/anm/player/ik/vehicles/hatchback/hatchback_trunk.anm");
    };
};