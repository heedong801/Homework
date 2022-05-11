#include "ThreadHandlerCharacterListMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "../ContentsStructure.h"

void ThreadHandlerCharacterListMessage::Start()
{
	Inst_->Characters_ = Message_->Characters;

	for (size_t i = 0; i < Inst_->Characters_.size(); i++)
	{
		FString Nick;
		UClientBlueprintFunctionLibrary::UTF8ToFString(Inst_->Characters_[i].NickName, Nick);

		int a = 0;
		 // Inst_->Characters_[i].NickName
	}

	UGameplayStatics::OpenLevel(World_, TEXT("CharacterSelectLevel"));

	// EGameServerCode Code

	// ·Î±×ÀÎ ui
}

