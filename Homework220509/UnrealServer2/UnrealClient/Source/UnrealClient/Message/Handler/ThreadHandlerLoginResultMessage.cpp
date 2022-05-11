#include "ThreadHandlerLoginResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"


void ThreadHandlerLoginResultMessage::Start()
{
	if (EGameServerCode::OK == Message_->Code)
	{

		// 이제부터는 캐릭터 정보를 불러오는 중입니다 서브창.
		// UGameplayStatics::OpenLevel(World_, TEXT("CharacterSelectLevel"));
		return;
	}

	// 실패한거니까 다시 로그인이 가능하다.
	Inst_->LoginProcess_ = false;

	// 로그인 ui
}

