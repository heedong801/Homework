// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RankUI.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API URankUI : public UUserWidget
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chat")
	class UListView* TopRankListView_;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chat")
		class UListView* MyRankListView_;


	UFUNCTION(BlueprintCallable, Category = "Create")
	void NewRankAdd(UObject* _Object, UUserWidget* _Widget);


protected:
	void NativeConstruct() override;


};
