// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayUIUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UPlayUIUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Create")
	void RankWindowOpen();

public:
	static void RankWindowOnOff();

private:
	static ESlateVisibility RankWindowMode;
	static class UWidget* RankWindow;

	void NativeConstruct() override;
};
