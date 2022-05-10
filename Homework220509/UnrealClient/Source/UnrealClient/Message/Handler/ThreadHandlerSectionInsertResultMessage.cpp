#include "ThreadHandlerSectionInsertResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../CharacterSelect/CharacterListItemObject.h"
#include "../../CharacterSelect/CharacterListItem.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "Components/ListView.h"
#include "../../UnrealClient.h"

void ThreadHandlerSectionInsertResultMessage::Start()
{
	if (EGameServerCode::FAIL == Message_->Code)
	{
		Inst_->LoginProcess_ = false;
		UGameplayStatics::OpenLevel(World_, TEXT("LoginLevel"));
		return;
	}

	if (Inst_->ObjectIndex == Message_->ObjectIndex)
	{
		int a = 0;
	}


	UE_LOG(ClientLog, Error, TEXT("%S(%u) > ObjectIndex [%d] SectionIndex [%d]"), __FUNCTION__, __LINE__, Message_->ObjectIndex, Message_->SectionIndex);
	Inst_->LoginProcess_ = false;
	Inst_->ObjectIndex = Message_->ObjectIndex;
	Inst_->ThreadIndex = Message_->ThreadIndex;
	Inst_->SectionIndex = Message_->SectionIndex;


	
	// 내 udp소켓도 만들면서
	// 서버의 udp포트도 세팅해 놓는걸로 생각할께요.
	if (false == Inst_->ServerUDPConnect("35000", Message_->UDPPort))
	{
		int a = 0;
	}
		
	FString NextLevelName;
	UClientBlueprintFunctionLibrary::UTF8ToFString(Message_->MoveLevel, NextLevelName);

	UGameplayStatics::OpenLevel(World_, *NextLevelName);

	int a = 0;
}

