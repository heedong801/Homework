// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/SlateEnums.h"
#include "ChatWindow.generated.h"

class UListView;
/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UChatWindow : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// UFUNCTION(BlueprintCallable, Category = "Login|Init")
	void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chat")
	FString ChatString_;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chat")
	UListView* MessageListView_;

	void MessageAdd(class UChatMessageObject* _ChatObject);

	void MessageAdd(FString _id, FString _Message);

	UFUNCTION(BlueprintCallable, Category = "Chat")
	void ChatSend(FString _Text, ETextCommit::Type _Type);

	UFUNCTION(BlueprintCallable, Category = "Chat")
	void NewMessageAdd(UObject* _Object, UUserWidget* _Widget);
};
