// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RankListItem.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API URankListItem : public UUserWidget
{
	GENERATED_BODY()
	

public:
	FORCEINLINE void SetNickName(const FString& _NickName)
	{
		NickName = _NickName;
	}

	FORCEINLINE void SetScore(const FString& _Score)
	{
		Score = _Score;
	}

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rank Data", meta = (AllowPrivateAccess = "true"))
	FString NickName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rank Data", meta = (AllowPrivateAccess = "true"))
	FString Score;
};
