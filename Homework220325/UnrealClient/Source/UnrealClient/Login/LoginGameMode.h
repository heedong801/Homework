// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "LoginUI.h"
#include "LoginGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API ALoginGameMode : public AGameMode
{
	GENERATED_BODY()
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	ULoginUI* m_LoginUI;
public:
	ALoginGameMode();

	void Tick(float _Delta) override;
	
	ULoginUI* GetLoginUI() { return m_LoginUI; }

	//UFUNCTION(BlueprintCallable, Category = "GameMode")
	//void SetLoginUI(ULoginUI* LoginUI) { m_LoginUI = m_LoginUI; }
};
