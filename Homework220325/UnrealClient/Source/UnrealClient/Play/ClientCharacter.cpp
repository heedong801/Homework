// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientCharacter.h"
#include "../UnrealClient.h"
#include "ClientAnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Math/NumericLimits.h"
#include "../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../Play/PlayGameMode.h"
#include "ObjectMessageComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AClientCharacter::AClientCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Messages = CreateDefaultSubobject<UObjectMessageComponent>(TEXT("ObjectMessageComponent"));

}

// Called when the game starts or when spawned
void AClientCharacter::BeginPlay()
{
	Super::BeginPlay();

	AnimationInst = Cast<UClientAnimInstance>(GetMesh()->GetAnimInstance());
	AnimationInst->SetAnimationMap(&Animations_);
	AnimationInst->ChangeAnimation(ClientAnimationType::Idle);
}

// Called every frame
void AClientCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AClientCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AClientCharacter::Destroyed()
{
	Super::Destroyed();

	APlayGameMode* PGameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (nullptr == PGameMode
		&& false == PGameMode->IsValidLowLevel())
	{
		return;
	}


	PGameMode->UnRegistObject(ObjectID_, GetObjectType(), this);
	int a = 0;
}

float AClientCharacter::LookTargetAddZ(AActor* _Target, float _Ratio)
{
	float Angle = LookZ((_Target->GetActorLocation() - GetActorLocation()).GetSafeNormal());
	// 내가 몇도였건
	// Angle
	// 내가 지금 40도 였는데.
	// 90도 돌아야 하는거죠?

	

	// 내가 바라봐야하는 무조건적인 각도죠?
	// 140도를 바라봐야되
	// 40
	FRotator NewRot = FRotator(0.0f, GetTransform().GetRotation().Euler().Z  + (Angle * _Ratio), 0.0f);
	SetActorRotation(NewRot);
	return Angle;
}

float AClientCharacter::LookTargetZ(AActor* _Target) 
{
	// 360도를 1초에 돌아라.
	// 360 * 델타타임
	// 90도가 나왔습니다. 0.25초
	// 

	float Angle = LookZ((_Target->GetActorLocation() - GetActorLocation()).GetSafeNormal());
	FRotator NewRot = FRotator(0.0f, Angle, 0.0f);
	SetActorRotation(NewRot);
	return Angle;
}

float AClientCharacter::LookZ(FVector _Dir, float _Ratio /*= 1.0f*/)
{
	// 캐릭터가 바라봐야하는 dir
	FVector LookVector = _Dir.GetSafeNormal();
	FVector CurVector = FRotator(0.0f, GetControlRotation().Yaw, 0.0f).Vector().GetSafeNormal();

	FVector CorssVector = FVector::CrossProduct(CurVector, LookVector);
	float DotValue = FVector::DotProduct(CurVector, LookVector);

	float ACos = FMath::Acos(DotValue);

	if (CorssVector.Z < 0)
	{
		ACos *= -1.0f;
	}

	return FMath::RadiansToDegrees(ACos) * _Ratio;
}

void AClientCharacter::DebugSphere(const FVector& _Dir, const FColor& _Color, float _Radius)
{
	DrawDebugSphere(GetWorld(), GetActorLocation() + _Dir, _Radius, 10, _Color, false, 0.5f, 0, 5.0f);
}



void AClientCharacter::DebugCircle(const FVector& _Dir, const FColor& _Color, float _Radius)
{
	DrawDebugCircle(GetWorld(), GetActorLocation() + _Dir, _Radius, 50, _Color, false, 0.5f, 0, 5.0f, GetActorRightVector(), GetActorForwardVector());
}



bool AClientCharacter::IsClientMode()
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (nullptr == Inst || false == Inst->IsValidLowLevel())
	{
		return false;
	}

	return Inst->GetClientMode();
}

UClientGameInstance* AClientCharacter::GetClientInst()
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (nullptr == Inst || false == Inst->IsValidLowLevel())
	{
		return false;
	}

	return Inst;
}