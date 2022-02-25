// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginGameMode.h"
#include "../Global/ClientGameInstance.h"


ALoginGameMode::ALoginGameMode() 
{
	// 맨처음 월드 아웃라이너에 배치한 액터등의 메모리는

	// char* NewAllStartActorMemory = new char[전체 다 합친만큼]
	// 플레이스먼트new이용해서 지연생성을 합니다.
	
	// 지울때도 비슷하게 지웁니다.
	
	// class A 
	// class B : public A
	
	// 소멸도 알아서 시키는데

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;

}

void ALoginGameMode::Tick(float _Delta) 
{
	// 이안에서 컴포넌트를 틱을 돌립니다.
	Super::Tick(_Delta);

	int a = 0;
}