// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginUI.h"
#include "../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "../Global/ClientBlueprintFunctionLibrary.h"
#include "../Message/Messages.h"

void ULoginUI::ServerConnect()
{
	


	// GetWorld() Level
	UGameplayStatics::GetPlayerController(GetWorld(), 0);
	

	UClientGameInstance* GameInst = Cast<UClientGameInstance>(GetGameInstance());

	// GameInst->GetLatentActionManager();

	// 이녀석도 쓰레드로 보내야 합니다.
	if (false == GameInst->ServerConnect(IPString, PORTString))
	{
		ConnectStatus = TEXT("접속 실패");
		return;
	}

	ConnectStatus = TEXT("접속 성공");
}


void ULoginUI::NativeConstruct()
{
	IPString = TEXT("127.0.0.1");
	PORTString = TEXT("30001");
	IDString = TEXT("Test");
	PWString = TEXT("Test");

	ConnectStatus = TEXT("커넥트 필요");
	LoginStatus = TEXT("로그인 필요");

}

void ULoginUI::ServerLogin() 
{
	UClientGameInstance* GameInst = Cast<UClientGameInstance>(GetGameInstance());


	std::string ID;
	std::string PW;
	UClientBlueprintFunctionLibrary::FStringToUTF8(IDString, ID);
	UClientBlueprintFunctionLibrary::FStringToUTF8(PWString, PW);

	LoginMessage NewPacket;
	NewPacket.ID = ID;
	NewPacket.PW = PW;
	GameServerSerializer Sr;
	NewPacket.Serialize(Sr);

	GameInst->ID = IDString;

	if (GameInst->Send(Sr.GetData()))
	{

	}
}

void ULoginUI::ResetInfo()
{
	IPString = TEXT("127.0.0.1");
	PORTString = TEXT("30001");
}