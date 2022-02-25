// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

// 여러분들이 헤더를 추가할때는 
// "xxxxxxx.generated.h" 헤더보다 위에 추가해야하는 규칙이 있습니다.

#include "LoginUI.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API ULoginUI : public UUserWidget
{
	GENERATED_BODY()

public:
	// FName
	// FText
	// FString
	// 언리얼에서 
	// FString 코드나 실시간 문자열을 처리할때 사용하게 된다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo")
	FString IPString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo")
	FString PORTString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo")
	FString ConnectStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LoginInfo")
	FString IDString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LoginInfo")
	FString PWString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LoginInfo")
	FString LoginStatus;



public:
	// UFUNCTION(BlueprintCallable, Category = "Login|Init")
	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Login|Connect")
	void ResetInfo();

	UFUNCTION(BlueprintCallable, Category = "Login|Connect")
	void ServerConnect();

	UFUNCTION(BlueprintCallable, Category = "Login|Login")
	void ServerLogin();

};
