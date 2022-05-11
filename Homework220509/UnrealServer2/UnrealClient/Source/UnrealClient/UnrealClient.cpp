// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealClient.h"
#include "Modules/ModuleManager.h"

// 게임 실행의 가장 핵심적인 우리의 게임이 들어가있는 메인 모듈
// IMPLEMENT_PRIMARY_GAME_MODULE

// xxx 분야에 관련된 코드들을 모아서 여러분들만의 sub모듈을 만들면 아래와 같이 define을 걸어줘야 합니다.
// IMPLEMENT_MODULE(FDefaultModuleImpl, PMG);

DEFINE_LOG_CATEGORY(ClientLog);

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, UnrealClient, "UnrealClient" );

