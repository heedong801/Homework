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

	if (0 != StartFunctions_.size())
	{

		for (auto& Function : StartFunctions_)
		{
			Function(CurrentAnimationType_);
		}
	}


	Montage_Play(FindAnimation);
}

void UClientAnimInstance::ChangeAnimation(ClientAnimationType _Type) 
{
	if (CurrentAnimationType_ == _Type)
	{
		return;
	}

	CurrentAnimationType_ = _Type;
}


bool UClientAnimInstance::IsCanMove()
{
	return CurrentAnimationType_ != ClientAnimationType::Attack;
}


void UClientAnimInstance::AnimNotify_End()
{
	if (0 == EndFunctions_.size())
	{
		return;
	}

	for (auto& Function : EndFunctions_)
	{
		Function(CurrentAnimationType_);
	}

	// CurrentAnimationType_ = ClientAnimationType::Idle;
}

void UClientAnimInstance::AddEndFunctionBind(std::function<void(ClientAnimationType)> _BindFunction)
{
	EndFunctions_.push_back(_BindFunction);
}

void UClientAnimInstance::AddStartFunctionBind(std::function<void(ClientAnimationType)> _BindFunction) 
{
	StartFunctions_.push_back(_BindFunction);
}