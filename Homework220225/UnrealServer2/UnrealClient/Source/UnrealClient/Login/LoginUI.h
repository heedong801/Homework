// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

// �����е��� ����� �߰��Ҷ��� 
// "xxxxxxx.generated.h" ������� ���� �߰��ؾ��ϴ� ��Ģ�� �ֽ��ϴ�.

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
	// �𸮾󿡼� 
	// FString �ڵ峪 �ǽð� ���ڿ��� ó���Ҷ� ����ϰ� �ȴ�.
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
