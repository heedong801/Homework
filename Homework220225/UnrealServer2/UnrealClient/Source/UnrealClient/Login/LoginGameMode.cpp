// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginGameMode.h"
#include "../Global/ClientGameInstance.h"


ALoginGameMode::ALoginGameMode() 
{
	// ��ó�� ���� �ƿ����̳ʿ� ��ġ�� ���͵��� �޸𸮴�

	// char* NewAllStartActorMemory = new char[��ü �� ��ģ��ŭ]
	// �÷��̽���Ʈnew�̿��ؼ� ���������� �մϴ�.
	
	// ���ﶧ�� ����ϰ� ����ϴ�.
	
	// class A 
	// class B : public A
	
	// �Ҹ굵 �˾Ƽ� ��Ű�µ�

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;

}

void ALoginGameMode::Tick(float _Delta) 
{
	// �̾ȿ��� ������Ʈ�� ƽ�� �����ϴ�.
	Super::Tick(_Delta);

	int a = 0;
}