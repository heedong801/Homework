#include "ThreadHandlerLoginResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"


void ThreadHandlerLoginResultMessage::Start()
{
	if (EGameServerCode::OK == Message_->Code)
	{

		// �������ʹ� ĳ���� ������ �ҷ����� ���Դϴ� ����â.
		// UGameplayStatics::OpenLevel(World_, TEXT("CharacterSelectLevel"));
		return;
	}

	// �����ѰŴϱ� �ٽ� �α����� �����ϴ�.
	Inst_->LoginProcess_ = false;

	// �α��� ui
}

