// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClientCharacter.h"
#include "ClientEnums.h"
#include "ClientPlayCharacter.generated.h"

UCLASS()
class UNREALCLIENT_API AClientPlayCharacter : public AClientCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AClientPlayCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void SendPlayerUpdatePacket();

	FVector MoveVector;
	FVector PrevVector;

	// 서버가 허락을 내렸냐?
	bool ServerPost;
	bool UDPReady;
	bool IsAttack;
	float AttTimeCheck;

	void MoveForward(float _Rate);
	void MoveRight(float _Rate);

	void MoveStart();
	void MoveEnd();

	void Attack();

	void AnimationStart(ClientAnimationType _Value);
	void AnimationEnd(ClientAnimationType _Value);

	FVector MouseVectorToWorldVector();

	// void TestPacketUpdate0();
};
