class Landrover_Wheel : CarWheel 
{
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);
		
		if (newLevel ==  GameConstants.STATE_RUINED)
		{
			string newWheel = "";
			switch (GetType())
			{
				case "Landrover_Wheel":
					newWheel = "Landrover_Wheel_Ruined";
				break;
			}
			
			if (newWheel != "")
			{
				if (IsLockedInSlot())
					UnlockFromParent();
				
				IEntity child = GetChildren();
				while (child)
				{
					RemoveChild(child, false);
					vector matrix[4];
					GetTransform(matrix);
					GetInventory().DropEntityWithTransform(InventoryMode.SERVER, this, EntityAI.Cast(child), matrix);
					child = GetSibling();
				}

				ReplaceWheelLambda lambda = new ReplaceWheelLambda(this, newWheel, null);
				lambda.SetTransferParams(true, true, true);
				GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, lambda);
			}
		}
	}

	override int GetMeleeTargetType()
	{
		return EMeleeTargetType.NONALIGNABLE;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
};

class Landrover_Wheel_Ruined : CarWheel_Ruined {};

class Landrover_Driver_Door : CarDoor 
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
};

class Landrover_CoDriver_Door : CarDoor 
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
};

class Landrover_Trunk : CarDoor 
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
};

class Landrover_Hood : CarDoor 
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
};