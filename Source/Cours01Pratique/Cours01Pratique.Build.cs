// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Cours01Pratique : ModuleRules
{
	public Cours01Pratique(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
