// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientCharacter.h"
#include "../UnrealClient.h"
#include "ClientAnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Math/NumericLimits.h"
#include "ObjectMessageComponent.h"

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
