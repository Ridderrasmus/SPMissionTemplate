class ReinforcementTrigger_Script_Class: SCR_BaseTriggerEntity 
{
	// user script
	protected int m_iCount; // keep count of enemies
 
    // Set up the filter 
	override bool ScriptedEntityFilterForQuery(IEntity ent) {
        SCR_ChimeraCharacter cc = SCR_ChimeraCharacter.Cast(ent);
        if (!cc) return false; // If the entity is not a person, filter it out
		if (!IsPlayer(cc)) return false; // If the entity is not a player, filter it out
        if (!IsAlive(cc)) return false; // If the entity is dead, filter it out
        return true; // Otherwise, include it!
    }
    
    bool IsPlayer(IEntity ent)
	{
	  int playerId = GetGame().GetPlayerManager().GetPlayerIdFromControlledEntity(ent);
	  return playerId > 0;
	}
	
	override void OnActivate(IEntity ent) 
	{
		IEntity thisTrigger = this;
		RIDDER_TriggerComponent myComponent = RIDDER_TriggerComponent.Cast(thisTrigger.FindComponent(RIDDER_TriggerComponent));
		
		vector targetLoc = GetWorld().FindEntityByName(myComponent.GetLocation()).GetOrigin();
		array<string> reinforcementGroups = myComponent.GetGroups();
		
		Resource resource = Resource.Load("{750A8D1695BD6998}Prefabs/AI/Waypoints/AIWaypoint_Move.et");
		
		AIWaypoint wp = AIWaypoint.Cast(GetGame().SpawnEntityPrefab(resource));
		wp.SetOrigin(targetLoc);
		
		foreach (int currentIndex, string currentElement : reinforcementGroups)
		{
			AIGroup grp = AIGroup.Cast(GetWorld().FindEntityByName(currentElement));
			grp.AddWaypoint(wp);
		}
	}

};