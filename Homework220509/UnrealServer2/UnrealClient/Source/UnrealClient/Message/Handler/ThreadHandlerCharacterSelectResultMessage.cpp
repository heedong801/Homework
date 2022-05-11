
#include "ThreadHandlerCharacterSelectResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../CharacterSelect/CharacterListItemObject.h"
#include "../../CharacterSelect/CharacterListItem.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"
#include "Components/ListView.h"
#include "../../UnrealClient.h"

void ThreadHandlerCharacterSelectResultMessage::Start()
{
	// 로딩이건 뭐건 고려 안함.
	// 지금 클라가 할게 없음
	// 물어봐야지
	// 로딩 고려하시면 됩니다.
	FString Nick;
	UClientBlueprintFunctionLibrary::UTF8ToFString(Message_->NickName, Nick);

	if (EGameServerCode::OK == Message_->Code)
	{
		for (size_t i = 0; i < Inst_->Characters_.size(); i++)
		{

			if (Inst_->Characters_[i].NickName == Message_->NickName)
			{
				Inst_->SelectCharacter = Inst_->Characters_[i];
				return;
			}
		}

		UE_LOG(ClientLog, Error, TEXT("%S(%u) > Charcter Client Data FAIL"), __FUNCTION__, __LINE__);
		Inst_->LoginProcess_ = false;
		UGameplayStatics::OpenLevel(World_, TEXT("LoginLevel"));
		// 에러 뿌려주고 터트린다.
	}

	// 로딩이 있다면 


}

