#include "ThreadHandlerServerDestroyMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../../Play/ChatWindow.h"
#include "../../Global/ClientBlueprintFunctionLibrary.h"


void ThreadHandlerServerDestroyMessage::Start()
{
	Inst_->Close();

	if (World_->GetName() != TEXT("LoginLevel"))
	{
		UGameplayStatics::OpenLevel(World_, TEXT("LoginLevel"));
		return;
	}
	
}

