// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealClient : ModuleRules
{
	public UnrealClient(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "SlateCore", "UMG" });


		PublicDependencyModuleNames.AddRange(new string[] { "Sockets", "Networking" });

		// cpp에서만 사용할 녀석은 여기에 넣어주면 됩니다.
		// 선언부에서는 이코드들이 보이지 않게 하겠다.
		// PrivateDependencyModuleNames.AddRange(new string[] { "Sockets", "Networking" });

		// c++로 언리얼의 그래픽 ui 시스템을사용하려면 
		// "UMG"


		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
