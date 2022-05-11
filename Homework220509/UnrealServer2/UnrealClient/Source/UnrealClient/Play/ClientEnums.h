// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ClientAnimationType : uint8 
{
	NONE UMETA(DisplayName = "애니메이션 지정 안됨"),
	Idle UMETA(DisplayName = "대기 애니메이션"),
	Move UMETA(DisplayName = "이동 애니메이션"),
	Attack UMETA(DisplayName = "공격 애니메이션"),
};