// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectUI.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UCharacterSelectUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CreateNickName")
	FString NickName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterList")
	class UListView* CharacterListView_;

	//void CharacterAdd();

	//void CharacterAdd();
	void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Create")
	void CharacterCreate();

	UFUNCTION(BlueprintCallable, Category = "Create")
		void NewCharacterAdd(UObject* _Object, UUserWidget* _Widget);
};