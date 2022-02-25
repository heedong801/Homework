// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClientEnums.h"
#include "../Message/Messages.h"
#include "ClientCharacter.generated.h"

UCLASS()
class UNREALCLIENT_API AClientCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AClientCharacter();

	FORCEINLINE class UClientAnimInstance* GetClientAnimInstance() 
	{
		return AnimationInst;
	}

	FORCEINLINE class UObjectMessageComponent* GetMessage()
	{
		return Messages;
	}

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientData", meta = (AllowPrivateAccess = "true"))
	TMap <ClientAnimationType, class UAnimMontage* > Animations_;

	class UClientAnimInstance* AnimationInst;

	class UObjectMessageComponent* Messages;
};
