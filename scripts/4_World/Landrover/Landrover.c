class Landrover_Base : CarScript
{
	protected ref UniversalTemperatureSource m_UTSource;
	protected ref UniversalTemperatureSourceSettings m_UTSSettings;
	protected ref UniversalTemperatureSourceLambdaEngine m_UTSLEngine;
	
	void Landrover_Base()
	{
		m_dmgContactCoef = 0.030;
		
		m_EngineStartOK 		= "offroad_engine_start_SoundSet";
		m_EngineStartBattery 	= "offroad_engine_failed_start_battery_SoundSet";
		m_EngineStartPlug 		= "offroad_engine_failed_start_sparkplugs_SoundSet";
		m_EngineStartFuel 		= "offroad_engine_failed_start_fuel_SoundSet";
		m_EngineStopFuel 		= "offroad_engine_stop_fuel_SoundSet";
		
		m_CarDoorOpenSound 		= "offroad_door_open_SoundSet";
		m_CarDoorCloseSound 	= "offroad_door_close_SoundSet";
		
		m_CarHornShortSoundName = "Offroad_Horn_Short_SoundSet";
		m_CarHornLongSoundName	= "Offroad_Horn_SoundSet";
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
 			m_UTSSettings 					= new UniversalTemperatureSourceSettings();
			m_UTSSettings.m_ManualUpdate 	= true;
			m_UTSSettings.m_TemperatureMin	= 0;
			m_UTSSettings.m_TemperatureMax	= 25;		// max temp 25 ----- Vanilla is 30;
			m_UTSSettings.m_RangeFull		= 0.5;
			m_UTSSettings.m_RangeMax		= 2;
			m_UTSSettings.m_TemperatureCap	= 25;
			
			m_UTSLEngine					= new UniversalTemperatureSourceLambdaEngine();
			m_UTSource						= new UniversalTemperatureSource(this, m_UTSSettings, m_UTSLEngine);
		}
	}
	
	override void OnEngineStart()
	{
		super.OnEngineStart();

		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.SetDefferedActive(true, 20.0);
		}
	}
	
	override void OnEngineStop()
	{
		super.OnEngineStop();

		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.SetDefferedActive(false, 10.0);
		}
	}
	
	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		super.EOnPostSimulate( other, timeSlice );
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			if (m_UTSource.IsActive())
			{
				m_UTSource.Update(m_UTSSettings, m_UTSLEngine);
			}
		}
	}
	
    override float GetActionDistanceFuel()
    {
        return 3.2;
    }
	
	override float GetActionDistanceCoolant()
    {
        return 4.2;
    }
	
	override float GetActionDistanceOil()
    {
        return 4.2;
    }
	
	override bool IsVitalTruckBattery()
	{
		return false;
	}

	override bool IsVitalGlowPlug()
	{
		return false;
	}
	
	override bool IsVitalCarBattery()
	{
		return true;
	}
	
	override int GetAnimInstance()
	{
		return VehicleAnimInstances.GOLF;
	}
	
	override float GetTransportCameraDistance()
	{
		return 6.5;
	}
	
	override vector GetTransportCameraOffset()
	{
		return "0 1.2 0";
	}
	
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast( ScriptedLightBase.CreateLight(LandroverRearLight) );
	}
	
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast( ScriptedLightBase.CreateLight(LandroverFrontLight) );
	}
	
	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor )
			return CarDoorState.DOORS_MISSING;
	
		switch ( slotType )
		{
			case "Landrover_Driver_Door":
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
            break;
			case "Landrover_CoDriver_Door":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
			case "Landrover_Trunk":
				if ( GetAnimationPhase("DoorsTrunk") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
            case "Landrover_Hood":
				if ( GetAnimationPhase("DoorsHood") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
		}
        return CarDoorState.DOORS_MISSING;
	}
	
	override string GetDoorConditionPointFromSelection( string selection )
	{
		switch (selection)
		{
			case "seat_driver":
				return "seat_con_1_1";
			break;
			case "seat_codriver":
				return "seat_con_2_1";
			break;
			case "seat_cargo1":
			case "seat_cargo2":
			case "seat_cargo3":
			case "seat_cargo4":
			case "seat_cargo5":
			case "seat_cargo6":
				return "seat_con_1_2";
			break;
        }
		return "";
	}

	override bool CrewCanGetThrough( int posIdx )
	{
		switch ( posIdx )
		{
			case 0:
				if ( GetCarDoorsState( "Landrover_Driver_Door" ) == CarDoorState.DOORS_CLOSED )
					return false;
                return true;
			break;
			case 1:
				if ( GetCarDoorsState( "Landrover_CoDriver_Door" ) == CarDoorState.DOORS_CLOSED )
					return false;
                return true;
			break;
			case 2:
				if ( GetCarDoorsState( "Landrover_Trunk" ) == CarDoorState.DOORS_CLOSED )
					return false;
                return true;
			break;
			case 3:
				if ( GetCarDoorsState( "Landrover_Trunk" ) == CarDoorState.DOORS_CLOSED )
					return false;
                return true;
			break;
			case 4:
				if ( GetCarDoorsState( "Landrover_Trunk" ) == CarDoorState.DOORS_CLOSED )
					return false;
                return true;
			break;
			case 5:
				if ( GetCarDoorsState( "Landrover_Trunk" ) == CarDoorState.DOORS_CLOSED )
					return false;
                return true;
			break;
			case 6:
				if ( GetCarDoorsState( "Landrover_Trunk" ) == CarDoorState.DOORS_CLOSED )
					return false;
                return true;
			break;
			case 7:
				if ( GetCarDoorsState( "Landrover_Trunk" ) == CarDoorState.DOORS_CLOSED )
					return false;
                return true;
			break;
        }
        return false;
	}
	
	override string GetDoorSelectionNameFromSeatPos(int posIdx)
	{
		switch ( posIdx )
		{
		case 0:
			return "doors_driver";
		break;
		case 1:
			return "doors_codriver";
		break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			return "doors_trunk";
		break;
        }
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}
	
	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch ( posIdx )
		{
		case 0:
			return "Landrover_Driver_Door";
		break;
		case 1:
			return "Landrover_CoDriver_Door";
		break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			return "Landrover_Trunk";
		break;

		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}
	
	override bool CanDisplayAttachmentCategory( string category_name )
	{
		if ( !super.CanDisplayAttachmentCategory( category_name ) )
			return false;
	
		category_name.ToLower();
		
		if ( category_name.Contains("engine") )
		{
			if ( GetCarDoorsState("Landrover_Hood") == CarDoorState.DOORS_CLOSED )
				return false;
		}
				
		return true;
	}
	
	override bool CanDisplayCargo()
	{
		if ( !super.CanDisplayCargo() )
			return false;
		
		if ( GetCarDoorsState("Landrover_Trunk") == CarDoorState.DOORS_CLOSED )
			return false;
		
		return true;
	}
	
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if ( !super.CanReleaseAttachment( attachment ) )
			return false;
		
		string attType = attachment.GetType();
		
		switch ( attType )
		{
			case "CarRadiator":
				if ( GetCarDoorsState("Landrover_Hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			case "HeadlightH7":
				if ( GetCarDoorsState("Landrover_Hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			case "CarBattery": 
				if ( GetCarDoorsState("Landrover_Driver_Door") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			case "SparkPlug":
				if ( GetCarDoorsState("Landrover_Hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			case "Landrover_Hood":
				if ( FindAttachmentBySlotName("Landrover_Sparewheel") )
					return false;
				return true;
			break;
		}

		return true;
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
		string slot_name = InventorySlots.GetSlotName(slotId);
        
        if ( slot_name == "Landrover_Sparewheel" && !FindAttachmentBySlotName( "Landrover_Hood" ) )
		{
			return false;
		}
		
        return true;
    }
	
	override string GetAnimSourceFromSelection( string selection )
	{
		switch ( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_trunk":
			return "DoorsTrunk";
		case "doors_hood":
			return "DoorsHood";
		}
        return "";
	}

	override int GetSeatAnimationType( int posIdx )
	{
		switch ( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
	    case 4:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		case 5:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 6:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		case 7:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
        }
		return 0;
	}
	override bool CanReachSeatFromSeat( int currentSeat, int nextSeat )
	{
		switch ( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 )
				return true;
		break;
		case 1:
			if ( nextSeat == 0 )
				return true;
		break;
		case 2:
			if ( nextSeat == 4 )
				return false;
		break;
		case 3:
			if ( nextSeat == 5 )
				return false;
		break;
		case 4:
			if ( nextSeat == 6 )
				return false;
		break;
		case 5:
			if ( nextSeat == 7 )
				return false;
		break;
		case 6:
			if ( nextSeat == 4 )
				return false;
		break;
		case 7:
			if ( nextSeat == 5 )
				return false;
		break;
        }
		return false;
	}

	override bool CanReachDoorsFromSeat( string pDoorsSelection, int pCurrentSeat )
	{
		switch ( pCurrentSeat )
		{
		case 0:
			if (pDoorsSelection == "DoorsDriver")
			{
				return true;
			}
		break;
		case 1:
			if (pDoorsSelection == "DoorsCoDriver")
			{
				return true;
			}
		break;
		case 2:
			if (pDoorsSelection == "DoorsTrunk")
			{
				return true;
			}
		break;
		case 3:
			if (pDoorsSelection == "DoorsTrunk")
			{
				return true;
			}
		break;
		case 4:
			if (pDoorsSelection == "DoorsTrunk")
			{
				return true;
			}
		break;
		case 5:
			if (pDoorsSelection == "DoorsTrunk")
			{
				return true;
			}
		break;
		case 6:
			if (pDoorsSelection == "DoorsTrunk")
			{
				return true;
			}
		break;
		case 7:
			if (pDoorsSelection == "DoorsTrunk")
			{
				return true;
			}
		break;
        }
		return false;		
	}
	
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );

			entity.GetInventory().CreateInInventory( "Landrover_Driver_Door" );
			entity.GetInventory().CreateInInventory( "Landrover_CoDriver_Door" );
			entity.GetInventory().CreateInInventory( "Landrover_Trunk" );
			entity.GetInventory().CreateInInventory( "Landrover_Hood" );

			entity.GetInventory().CreateInInventory( "Landrover_Wheel" );
			entity.GetInventory().CreateInInventory( "Landrover_Wheel" );
			entity.GetInventory().CreateInInventory( "Landrover_Wheel" );
			entity.GetInventory().CreateInInventory( "Landrover_Wheel" );
			
			entity.GetInventory().CreateInInventory( "Landrover_Wheel" ); //Spare Wheel can only attach if Hood is attached

			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		FillUpCarFluids();
	}
	
	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 0;
				
				if ( GetCarDoorsState( "Landrover_Driver_Door" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
				
				if ( GetCarDoorsState( "Landrover_CoDriver_Door" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
				
	         	if ( GetCarDoorsState( "Landrover_Trunk" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
				
				if ( GetCarDoorsState( "Landrover_Hood" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
					
				if ( newValue > 1 )
					newValue = 1;
			
				return newValue;
			break;
		}

		return oldValue;
	}
};

class Landrover : Landrover_Base{};