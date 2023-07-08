// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class unreal_project_1 : ModuleRules
{
	public unreal_project_1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
