// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientAnimInstance.h"
#include "../UnrealClient.h"

UClientAnimInstance::UClientAnimInstance() 
	: Animations_(nullptr)
{

}

void UClientAnimInstance::NativeUpdateAnimation(float _DeltaTime)
{
	if (nullptr == Animations_) 
	{
		return;
	}

	Super::NativeUpdateAnimation(_DeltaTime);

	if (false == (*Animations_).Contains(CurrentAnimationType_))
	{
		return;
	}

	UAnimMontage* FindAnimation = (* Animations_)[CurrentAnimationType_];

	if (nullptr == FindAnimation)
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > Animation Is Null"), __FUNCTION__, __LINE__);
	}

	if (true == Montage_IsPlaying(FindAnimation))
	{
		return;
	}

	Montage_Play(FindAnimation);
}

void UClientAnimInstance::ChangeAnimation(ClientAnimationType _Type) {
	CurrentAnimationType_ = _Type;
}


bool UClientAnimInstance::IsCanMove()
{
	return CurrentAnimationType_ != ClientAnimationType::Attack;
}


void UClientAnimInstance::AnimNotify_End()
{
	CurrentAnimationType_ = ClientAnimationType::Idle;
}