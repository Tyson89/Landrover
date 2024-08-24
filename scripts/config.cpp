class CfgPatches
{
	class Landrover_Scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"Landrover"
		};
	};
};
class CfgSlots
{
	class Slot_Landrover_Wheel_1_1
	{
		name="Landrover_Wheel_1_1";
		displayName="Landrover Wheel";
		selection="wheel_1_1";
		ghostIcon="set:dayz_inventory image:wheel";
	};
	class Slot_Landrover_Wheel_2_1
	{
		name="Landrover_Wheel_2_1";
		displayName="Landrover Wheel";
		selection="wheel_2_1";
		ghostIcon="set:dayz_inventory image:wheel";
	};
	class Slot_Landrover_Wheel_2_2
	{
		name="Landrover_Wheel_2_2";
		displayName="Landrover Wheel";
		selection="wheel_2_2";
		ghostIcon="set:dayz_inventory image:wheel";
	};
	class Slot_Landrover_Wheel_1_2
	{
		name="Landrover_Wheel_1_2";
		displayName="Landrover Wheel";
		selection="wheel_1_2";
		ghostIcon="set:dayz_inventory image:wheel";
	};
	class Slot_Landrover_Sparewheel
	{
		name="Landrover_Sparewheel";
		displayName="Landrover Spare Wheel";
		selection="Landrover_Sparewheel";
		ghostIcon="set:dayz_inventory image:wheel";
	};
    class Slot_Landrover_Hood
	{
		name="Landrover_Hood";
		displayName="Landrover Hood";
		selection = "doors_hood";
		ghostIcon="set:dayz_inventory image:hood";
	};
	class Slot_Landrover_Trunk
	{
		name="Landrover_Trunk";
		displayName="Landrover Trunk";
		selection = "doors_trunk";
		ghostIcon="set:dayz_inventory image:trunk";
	};
	class Slot_Landrover_Driver_Door
	{
		name="Landrover_Driver_Door";
		displayName="Landrover Driver Door";
		selection="doors_driver";
		ghostIcon="set:dayz_inventory image:doorfront";
	};
	class Slot_Landrover_CoDriver_Door
	{
		name="Landrover_CoDriver_Door";
		displayName="Landrover CoDriver Door";
		selection="doors_codriver";
		ghostIcon="set:dayz_inventory image:doorfront";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyVehiclePart: ProxyAttachment
	{
		scope=2;
		simulation="ProxyInventory";
		autocenter=0;
		animated=0;
		shadow=1;
		reversed=0;
	};
	class ProxyLandrover_Driver_Door: ProxyVehiclePart
	{
		Model = "\Landrover\proxy\Landrover_Driver_Door.p3d";
		inventorySlot="Landrover_Driver_Door";
	};
	class ProxyLandrover_CoDriver_Door: ProxyVehiclePart
	{
		Model = "\Landrover\proxy\Landrover_CoDriver_Door.p3d";
		inventorySlot="Landrover_CoDriver_Door";
	};
	class ProxyLandrover_Hood: ProxyVehiclePart
	{
		Model = "\Landrover\proxy\Landrover_Hood.p3d";
		inventorySlot="Landrover_Hood";
	};
	class ProxyLandrover_Trunk: ProxyVehiclePart
	{
		Model = "\Landrover\proxy\Landrover_Trunk.p3d";
		inventorySlot="Landrover_Trunk";
	};
	class ProxyLandrover_Wheel: ProxyVehiclePart
	{
		model="\Landrover\proxy\Landrover_Wheel.p3d";
		inventorySlot[]=
		{
			"Landrover_Wheel_1_1",
		    "Landrover_Wheel_1_2",
			"Landrover_Wheel_2_1",
			"Landrover_Wheel_2_2",
			"Landrover_Sparewheel"
		};
	};
	class ProxyLandrover_Wheel_Ruined: ProxyVehiclePart
	{
		model="\Landrover\proxy\Landrover_Wheel_Ruined.p3d";
		inventorySlot[]=
		{
			"Landrover_Wheel_1_1",
		    "Landrover_Wheel_1_2",
			"Landrover_Wheel_2_1",
			"Landrover_Wheel_2_2",
			"Landrover_Sparewheel"
		};
	};
};