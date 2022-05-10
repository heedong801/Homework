// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterListItem.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UCharacterListItem : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharcterInfo")
	FString NickName;

	UFUNCTION(BlueprintCallable, Category = "Login|Connect")
	void CharacterSelect();
};
