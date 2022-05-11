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
	UFUNCTION(BlueprintCallable, Category = "Create")
	void NewRankAdd(UObject* _Object, UUserWidget* _Widget);

	//static class UListView* GetTopRankListView()
	//{
	//	return TopRankListView_;
	//}

	//static class UListView* GetMyRankListView()
	//{
	//	return MyRankListView_;
	//}
	void Test();

protected:
	void NativeConstruct() override;


};
