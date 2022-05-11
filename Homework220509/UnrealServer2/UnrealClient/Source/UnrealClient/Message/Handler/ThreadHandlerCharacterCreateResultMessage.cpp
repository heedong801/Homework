#include "ThreadHandlerCharacterCreateResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../CharacterSelect/CharacterListItemObject.h"
#include "../../CharacterSelect/CharacterListItem.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "Components/ListView.h"

void ThreadHandlerCharacterCreateResultMessage::Start()
{
	if (EGameServerCode::OK == Message_->Code)
	{
		Inst_->Characters_.push_back(Message_->ResultCharacter);
		UCharacterListItemObject* NewCharacterObject = NewObject<UCharacterListItemObject>();
		NewCharacterObject->Info = Message_->ResultCharacter;
		UClientBlueprintFunctionLibrary::UTF8ToFString(NewCharacterObject->Info.NickName, NewCharacterObject->ConvertNickName);
		Inst_->CharacterListView_->AddItem(NewCharacterObject);
		Inst_->CharacterListView_->SetScrollOffset(Inst_->CharacterListView_->GetNumItems() * 50.0f);
	}
	else 
	{
		// 로그를 찍는다.
	}
}

