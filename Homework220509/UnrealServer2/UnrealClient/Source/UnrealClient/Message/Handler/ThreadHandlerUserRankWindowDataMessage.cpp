
#include "ThreadHandlerUserRankWindowDataMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../CharacterSelect/CharacterListItem.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "Components/ListView.h"
#include "../../UnrealClient.h"
#include "../../Play/PlayGameMode.h"
#include "../../Play/ClientCharacter.h"
#include "../../Play/UserRankItemObject.h"
#include "../../Play/RankListItem.h"
#include "Components/ListView.h"
#include "../../Play/RankUI.h"


void ThreadHandlerUserRankWindowDataMessage::Start()
{
	APlayGameMode* PGameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(World_));

	if (nullptr == PGameMode
		|| false == PGameMode->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > GameMode Is nullptr"), __FUNCTION__, __LINE__);
		return;
	}

	//URankUI::GetTopRankListView()->ClearListItems();
	//URankUI::GetMyRankListView()->ClearListItems();

	//
	for (size_t i = 0; i < Message_->TopUserName.size(); i++)
	{
		UUserRankItemObject* UserRankObject = NewObject<UUserRankItemObject>();
		UClientBlueprintFunctionLibrary::UTF8ToFString(Message_->TopUserName[i], UserRankObject->ConvertNickName);
		UserRankObject->Score = Message_->TopUserScore[i];
		// URankUI::GetTopRankListView()->AddItem(UserRankObject);
	}

	//for (size_t i = 0; i < Message_->MyUserName.size(); i++)
	//{
	//	UUserRankItemObject* UserRankObject = NewObject<UUserRankItemObject>();
	//	UClientBlueprintFunctionLibrary::UTF8ToFString(Message_->MyUserName[i], UserRankObject->ConvertNickName);
	//	UserRankObject->Score = Message_->MyUserScore[i];
	//	URankUI::GetMyRankListView()->AddItem(UserRankObject);
	//}

}

