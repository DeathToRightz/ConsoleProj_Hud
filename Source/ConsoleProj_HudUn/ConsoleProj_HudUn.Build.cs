// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ConsoleProj_HudUn : ModuleRules
{
	public ConsoleProj_HudUn(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ConsoleProj_HudUn",
			"ConsoleProj_HudUn/Variant_Horror",
			"ConsoleProj_HudUn/Variant_Horror/UI",
			"ConsoleProj_HudUn/Variant_Shooter",
			"ConsoleProj_HudUn/Variant_Shooter/AI",
			"ConsoleProj_HudUn/Variant_Shooter/UI",
			"ConsoleProj_HudUn/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
