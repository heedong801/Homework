// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ClientEnums.h"
#include "ClientAnimInstance.generated.h"

class UAnimMontage;
/**
 * 
 */

UCLASS()
class UNREALCLIENT_API UClientAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	FORCEINLINE void SetAnimationMap(TMap <ClientAnimationType, UAnimMontage* >* _Map)
	{
		Animations_ = _Map;
	}

	FORCEINLINE ClientAnimationType GetAnimationType()
	{
		return CurrentAnimationType_;
	}

	void ChangeAnimation(ClientAnimationType _Type);

	bool IsCanMove();

	UClientAnimInstance();

protected:
	void NativeUpdateAnimation(float _DeltaTime);

	UFUNCTION()
	void AnimNotify_End();

private:
	ClientAnimationType CurrentAnimationType_;

	TMap <ClientAnimationType, UAnimMontage* >* Animations_;
};
