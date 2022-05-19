// Fill out your copyright notice in the Description page of Project Settings.


#include "RankUI.h"
#include "../Play/UserRankItemObject.h"
#include "../Play/RankListItem.h"
#include "../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../Global/ClientBlueprintFunctionLibrary.h"
#include "../Message/Messages.h"
#include "Components/ListView.h"
#include "../UnrealClient.h"
#include "../Message/ServerToClient.h"
#include "../Message/ServerAndClient.h"
#include "../Message/ClientToServer.h"



void URankUI::NewRankAdd(UObject* _Object, UUserWidget* _Widget)
{
	UUserRankItemObject* Info = Cast<UUserRankItemObject>(_Object);
	URankListItem* Widget = Cast<URankListItem>(_Widget);

	if (nullptr == Info
		 || false == Info->IsValidLowLevel())
	{
		return;
	}

	if (nullptr == Widget
		|| false == Widget->IsValidLowLevel())
	{
		return;
	}

	Widget->SetNickName(Info->ConvertNickName);
	Widget->SetScore(FString::FromInt(Info->Score));
}

void URankUI::NativeConstruct()
{

	Super::NativeConstruct();


	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetGameInstance());
	//Inst->ChatWindow_ = this;

	Inst->TopRankListView_ = Cast<UListView>(GetWidgetFromName(TEXT("TopRankList")));
	Inst->MyRankListView_ = Cast<UListView>(GetWidgetFromName(TEXT("MyRankList")));

	TopRankListView_ = Inst->TopRankListView_;
	MyRankListView_ = Inst->MyRankListView_;

	// RankListView_->ClearListItems();


	if (nullptr == Inst->TopRankListView_
		|| false == Inst->TopRankListView_->IsValidLowLevel())
	{
		int a = 0;
		return;
	}


	if (nullptr == Inst->MyRankListView_
		|| false == Inst->MyRankListView_->IsValidLowLevel())
	{
		int a = 0;
		return;
	}

	Inst->TopRankListView_->ClearListItems();
	Inst->MyRankListView_->ClearListItems();

	for (size_t i = 0; i < 5; i++)
	{
		UUserRankItemObject* UserRankObject = NewObject<UUserRankItemObject>();
		UserRankObject->ConvertNickName = TEXT("Test");
		UserRankObject->Score = 100000;
		Inst->TopRankListView_->AddItem(UserRankObject);
	}

	for (size_t i = 0; i < 5; i++)
	{
		UUserRankItemObject* UserRankObject = NewObject<UUserRankItemObject>();
		UserRankObject->ConvertNickName = TEXT("Test");
		UserRankObject->Score = 100000;
		Inst->MyRankListView_->AddItem(UserRankObject);
	}


}

