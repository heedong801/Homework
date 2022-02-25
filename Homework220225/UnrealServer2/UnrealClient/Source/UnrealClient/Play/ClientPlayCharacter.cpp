#include "ClientPlayCharacter.h"
#include "../UnrealClient.h"
#include "../Global/ClientGameInstance.h"
#include "Animation/AnimMontage.h"
#include "ClientAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerInput.h"

// Sets default values
AClientPlayCharacter::AClientPlayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AClientPlayCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AClientPlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AClientPlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	static bool bBindingsAdded = false;
	if (!bBindingsAdded)
	{
		bBindingsAdded = true;

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("ClientPlayer_MoveForward", EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("ClientPlayer_MoveForward", EKeys::S, -1.f));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Move", EKeys::W));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Move", EKeys::S));


		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("ClientPlayer_MoveRight", EKeys::D, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("ClientPlayer_MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Move", EKeys::D));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Move", EKeys::A));

		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ClientPlayer_Attack", EKeys::LeftMouseButton));

		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket0", EKeys::NumPadZero));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket1", EKeys::NumPadOne));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket2", EKeys::NumPadTwo));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket3", EKeys::NumPadThree));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket4", EKeys::NumPadFour));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket5", EKeys::NumPadFive));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket6", EKeys::NumPadSix));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket7", EKeys::NumPadSeven));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket8", EKeys::NumPadEight));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("TestPacket9", EKeys::NumPadNine));
	}

	// �󸶳� ���������� ���������� ���� ������ ���ϰ� �����ٴ� üũ�ؾ��Ҷ��� �����ϴ�.
	// ���� ���� Ű�� �ԷµǾ����� 
	PlayerInputComponent->BindAxis("DefaultPawn_MoveForward", this, &AClientPlayCharacter::MoveForward);
	PlayerInputComponent->BindAxis("ClientPlayer_MoveRight", this, &AClientPlayCharacter::MoveRight);
	PlayerInputComponent->BindAction("ClientPlayer_Move", EInputEvent::IE_Pressed, this, &AClientPlayCharacter::MoveStart);
	PlayerInputComponent->BindAction("ClientPlayer_Move", EInputEvent::IE_Released, this, &AClientPlayCharacter::MoveEnd);

	PlayerInputComponent->BindAction("ClientPlayer_Attack", EInputEvent::IE_Released, this, &AClientPlayCharacter::Attack);
	PlayerInputComponent->BindAction("TestPacket0", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate0);
	PlayerInputComponent->BindAction("TestPacket1", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate1);
	PlayerInputComponent->BindAction("TestPacket2", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate2);
	PlayerInputComponent->BindAction("TestPacket3", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate3);
	PlayerInputComponent->BindAction("TestPacket4", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate4);
	PlayerInputComponent->BindAction("TestPacket5", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate5);
	PlayerInputComponent->BindAction("TestPacket6", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate6);
	PlayerInputComponent->BindAction("TestPacket7", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate7);
	PlayerInputComponent->BindAction("TestPacket8", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate8);
	PlayerInputComponent->BindAction("TestPacket9", EInputEvent::IE_Released, this, &AClientPlayCharacter::TestPacketUpdate9);

	FInputModeGameAndUI InputMode;
	GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}

void AClientPlayCharacter::LookZ(FVector _Dir, float _Ratio /*= 1.0f*/) 
{
	// ĳ���Ͱ� �ٶ�����ϴ� dir
	FVector LookVector = _Dir.GetSafeNormal();
	FVector CurVector = FRotator(0.0f, GetControlRotation().Yaw, 0.0f).Vector().GetSafeNormal();

	FVector CorssVector = FVector::CrossProduct(CurVector, LookVector);
	float DotValue = FVector::DotProduct(CurVector, LookVector);

	float ACos = FMath::Acos(DotValue);

	if (CorssVector.Z < 0)
	{
		ACos *= -1.0f;
	}

	AddControllerYawInput(FMath::RadiansToDegrees(ACos) * _Ratio);
}

void AClientPlayCharacter::MoveRight(float _Rate) 
{
	if (false == GetClientAnimInstance()->IsCanMove())
	{
		return;
	}

	if (0.0f == _Rate)
	{
		return;
	}

	LookZ(FVector(1.0f, 1.0f, 0.0f).GetSafeNormal() * _Rate, 0.1f);

	AddMovementInput(FVector(1.0f, 1.0f, 0.0f).GetSafeNormal(), _Rate);
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);
}

void AClientPlayCharacter::MoveForward(float _Rate) 
{
	if (false == GetClientAnimInstance()->IsCanMove())
	{
		return;
	}

	if (0.0f == _Rate)
	{
		return;
	}

	LookZ(FVector(1.0f, -1.0f, 0.0f).GetSafeNormal() * _Rate, 0.1f);

	AddMovementInput(FVector(1.0f, -1.0f, 0.0f).GetSafeNormal(), _Rate);
	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);
}

void AClientPlayCharacter::MoveStart()
{
	if (false == GetClientAnimInstance()->IsCanMove())
	{
		return;
	}

	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Move);
}

void AClientPlayCharacter::MoveEnd()
{
	if (false == GetClientAnimInstance()->IsCanMove())
	{
		return;
	}


	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Idle);
}

void AClientPlayCharacter::Attack() 
{
	// ȭ���� �ٶ󺸴°� Ŭ���̾�Ʈ ���Դϴ�.

	// LookZ(FVector(1.0f, -1.0f, 0.0f).GetSafeNormal() * _Rate, 0.1f);

	LookZ(MouseVectorToWorldVector() - GetActorLocation());

	GetClientAnimInstance()->ChangeAnimation(ClientAnimationType::Attack);
}


FVector AClientPlayCharacter::MouseVectorToWorldVector()
{
	APlayerController* PC = Cast<APlayerController>(GetController());

	if (nullptr == PC && PC->IsValidLowLevel())
	{
		UE_LOG(ClientLog, Error, TEXT("%S(%u) > nullptr Controller"), __FUNCTION__, __LINE__);
		// ���ѰŴ�. 
		return FVector(TNumericLimits<float>::Max(), TNumericLimits<float>::Max(), TNumericLimits<float>::Max());
	}

	FHitResult TraceHitResult;

	if (false == PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult))
	{
		//     ���� ��ǥ�̱� ������
		return FVector(TNumericLimits<float>::Max(), TNumericLimits<float>::Max(), TNumericLimits<float>::Max());
	}
	
	return TraceHitResult.Location;
}


void AClientPlayCharacter::TestPacketUpdate0()
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (nullptr == Inst || false == Inst->IsValidLowLevel())
	{
		return;
	}

#include "../Message/ServerToClient.h"
	std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
	Message->Pos = FVector(500.0f, 500.0f, 200.0f);
	Message->MonsterType = 0;
	Inst->PushMessage(Message);

}
void AClientPlayCharacter::TestPacketUpdate1() 
{
	UClientGameInstance* Inst = Cast<UClientGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	if (nullptr == Inst || false == Inst->IsValidLowLevel())
	{
		return;
	}

#include "../Message/ServerToClient.h"
	std::shared_ptr<MonsterUpdateMessage> Message = std::make_shared<MonsterUpdateMessage>();
	Message->Pos = FVector(300.0f, 300.0f, 200.0f);
	Message->MonsterType = 0;
	Inst->PushMessage(Message);

}
void AClientPlayCharacter::TestPacketUpdate2() {}
void AClientPlayCharacter::TestPacketUpdate3() {}
void AClientPlayCharacter::TestPacketUpdate4() {}
void AClientPlayCharacter::TestPacketUpdate5() {}
void AClientPlayCharacter::TestPacketUpdate6() {}
void AClientPlayCharacter::TestPacketUpdate7() {}
void AClientPlayCharacter::TestPacketUpdate8() {}
void AClientPlayCharacter::TestPacketUpdate9() {}