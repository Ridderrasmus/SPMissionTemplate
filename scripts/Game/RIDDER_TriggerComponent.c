[ComponentEditorProps(category: "RIDDER/Components", description: "Makes trigger be doing reinforcement stuff", color: "0 0 255 255")]
class RIDDER_TriggerComponentClass: ScriptComponentClass
{
};



class RIDDER_TriggerComponent : ScriptComponent 
{
	[Attribute("", UIWidgets.EditBox, "List of group names that will use this waypoint", category: "Reinforcement")] 
	ref array<string> RIDDER_GroupsToReinforce;
	
	array<string> GetGroups () 
	{
		return RIDDER_GroupsToReinforce;
	};
	
	
	[Attribute("", UIWidgets.Auto, "Target location", category: "Reinforcement")]
	string RIDDER_TargetLoc;
	
	string GetLocation ()
	{
		return RIDDER_TargetLoc;
	};
	
};