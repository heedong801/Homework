// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
// 언리얼에서 관리해주기 위한 코드와 관련된 헤더
#include "FreeCameraPawn.generated.h"

// 언리얼만의 추가 컴파일러 기능이 따로 있을것이다.
// 

class USphereComponent;
class UStaticMeshComponent;
class UPawnMovementComponent;
// UClass가 있어야 언리얼 컨텐츠 브라우저 c++ 항목에서 표시할수 있는
// 클래스가 된다.
UCLASS()
class UNREALCLIENT_API AFreeCameraPawn : public APawn
{
	// 언리얼에서 기본 관리를 하기 위해서 
	// 필요한 코드 내용을 채워주는 용도로 
	GENERATED_BODY()

public:
	static FName MovementComponentName;
	static FName CollisionComponentName;
	static FName MeshComponentName;

	/** If true, adds default input bindings for movement and camera look. */
	UPROPERTY(Category = Pawn, EditAnywhere, BlueprintReadOnly)
		uint32 bAddDefaultMovementBindings : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
		float BaseLookUpRate;

protected:
	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UPawnMovementComponent* MovementComponent;

private:
	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		USphereComponent* CollisionComponent;

	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* MeshComponent;


public:
	AFreeCameraPawn();

	UFUNCTION(BlueprintCallable, Category = "Pawn")
	virtual void MoveForward(float Val);

	UFUNCTION(BlueprintCallable, Category = "Pawn")
	virtual void MoveRight(float Val);

	UFUNCTION(BlueprintCallable, Category = "Pawn")
	virtual void MoveUp_World(float Val);

	UFUNCTION(BlueprintCallable, Category = "Pawn")
	void Move_Test();

	void Mouse_On();

	void Mouse_Off();


protected:
	virtual void BeginPlay() override;

private:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
