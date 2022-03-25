// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClientEnums.h"
#include "../Message/Messages.h"
#include "../Message/ContentsEnums.h"
#include "ClientCharacter.generated.h"

class UClientGameInstance;
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

	FORCEINLINE EGameObjectType GetObjectType()
	{
		return ObjectType_;
	}

	FORCEINLINE int GetObjectId()
	{
		return ObjectID_;
	}

	FORCEINLINE void SetObjectType(EGameObjectType _Type)
	{
		ObjectType_ = _Type;
	}

	FORCEINLINE void SetId(int _ObjectID)
	{
		ObjectID_ = _ObjectID;
	}

	virtual void ObjectInit() {}

	bool IsClientMode();

	UClientGameInstance* GetClientInst();

	// 내 액터를 
	float LookZ(FVector _Dir, float _Ratio = 1.0f);

protected:
	float LookTargetAddZ(AActor* _Target, float _Ratio);

	float LookTargetZ(AActor* _Target);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Destroyed() override;

public:
	void DebugSphere(const FVector& _Dir, const FColor& _Color ,  float _Radius);

	void DebugCircle(const FVector& _Dir, const FColor& _Color, float _Radius);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientData", meta = (AllowPrivateAccess = "true"))
	TMap <ClientAnimationType, class UAnimMontage* > Animations_;

	class UClientAnimInstance* AnimationInst;

	class UObjectMessageComponent* Messages;

	int ObjectID_;

	EGameObjectType ObjectType_;
};
