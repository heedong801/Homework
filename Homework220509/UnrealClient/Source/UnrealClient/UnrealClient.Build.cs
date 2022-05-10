// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealClient : ModuleRules
{
	public UnrealClient(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "SlateCore", "UMG" });


		PublicDependencyModuleNames.AddRange(new string[] { "Sockets", "Networking" });

		// cpp������ ����� �༮�� ���⿡ �־��ָ� �˴ϴ�.
		// ����ο����� ���ڵ���� ������ �ʰ� �ϰڴ�.
		// PrivateDependencyModuleNames.AddRange(new string[] { "Sockets", "Networking" });

		// c++�� �𸮾��� �׷��� ui �ý���������Ϸ��� 
		// "UMG"


		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
