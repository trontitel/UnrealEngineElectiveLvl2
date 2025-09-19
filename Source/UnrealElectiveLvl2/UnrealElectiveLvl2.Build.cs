// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealElectiveLvl2 : ModuleRules
{
	public UnrealElectiveLvl2(ReadOnlyTargetRules Target) : base(Target)
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
			"UnrealElectiveLvl2",
			"UnrealElectiveLvl2/Variant_Horror",
			"UnrealElectiveLvl2/Variant_Horror/UI",
			"UnrealElectiveLvl2/Variant_Shooter",
			"UnrealElectiveLvl2/Variant_Shooter/AI",
			"UnrealElectiveLvl2/Variant_Shooter/UI",
			"UnrealElectiveLvl2/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
