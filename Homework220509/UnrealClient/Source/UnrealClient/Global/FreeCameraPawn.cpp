// Fill out your copyright notice in the Description page of Project Settings.


#include "FreeCameraPawn.h"
#include "Components/SphereComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerInput.h"
#include "../UnrealClient.h"

FName AFreeCameraPawn::MovementComponentName(TEXT("MovementComponent0"));
FName AFreeCameraPawn::CollisionComponentName(TEXT("CollisionComponent0"));
FName AFreeCameraPawn::MeshComponentName(TEXT("MeshComponent0"));

// Sets default values
AFreeCameraPawn::AFreeCameraPawn()
{
	// �����ڿ��� �ۼ��Ǵ� �ڵ�� �������� ���� ������ �⺻ ������ ���ǳ����� �ֽ��ϴ�.
	// �ʱ�ȭ�� ������ ��û���� �ٸ� ��������
	// �𸮾󿡼� ��� �������Ʈ Ŭ������ ���鶧
	// �׳༮�� ó�� �ѹ� ���Ӱ� �����մϴ�.

	// �̰� CDO��� �մϴ�.
	// CreateDefaultObject

	// ����� ����
	// �θ�Ŭ������ ������� ��ɵ鵵 �ڽĵ��� �����޴´�.
	// ��? ���� ��ȭ����� �ʿ���µ�?
	// ��? ���� ���� �Ⱥε�ġ�µ�?
	// ��ΰ� �̰� ������....
	// => �Ⱦ��� ��ɵ鵵 ���������� ��ӹ޴� ��찡 �������� �ȴ�.
	
	// ��� ��ü�� Ŭ������ �����
	// �� ��ɸ� ��� ������ ����Ҽ� �ִ�.
	// �̰� Component(���� ���ϴ� ���)��� �ϴ� �θ�Ŭ������ ���ؼ�
	// �ϳ��� �����ϴ°��� ������Ʈ ������� �մϴ�.
	// std::list<Component*>

	// ��ȭ�� �Ҽ� �ִ�.
	// class Talk : pubic Component
	// class Jump : pubic Component

	// �л����� �����ؾ��� ����
	// ��ġ. ��� VS ������Ʈ(����� �ϸ� �ȵ�)
	// ���� ��ȣ ��ȯ ���� �����̰�.
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// �浹�����ε�
	// �浹 ����ü�� Damage��
	SetCanBeDamaged(true);

	SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	bReplicates = true;
	// �𸮾� ������ �ٸ� ������ ������ 

	NetPriority = 3.0f;

	BaseEyeHeight = 0.0f;
	bCollideWhenPlacing = false;
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// CreateDefaultSubobject �������Ʈ�� �����Ǳ���
	// �� Ŭ������ ����ϴ� �������Ʈ���� �⺻����� �����ڿ��� �������ټ� �ִ�.
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(AFreeCameraPawn::CollisionComponentName);
	CollisionComponent->InitSphereRadius(35);

	// �浹 �׷�
	// ���� �Ѿ� 
	// ���� �׷� 
	// Ŭ��� ������ ������ �ǻ������ �� �켱�ɰ��ΰ�? 
	// Ŭ�� �����°� �������� ���� �������� ���ԵǴ� ���̰�
	// ������ ��� ������ ������
	// �׼Ǽ��� �װ� �˴ϴ�.
	// �ξư� �� �׼Ǽ��� �پ ������? ä���� �����ų�
	// �Ϳ� ���ڸ��� 100���� �𿴾�
	// �Ȱ�ġ�� ������ ��κ� Ŭ�� �մϴ�.
	// ������ ��� ���������� �� �����غ���
	// ��� �κ��� Ŭ�� ó���ϰ� ����κ��� ������ ó���ϴ��� �����غ��� �ֽ��ϴ�.
	// �����Ե� Pve�� �Ѵ�.
	CollisionComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	CollisionComponent->SetShouldUpdatePhysicsVolume(true);
	CollisionComponent->SetCanEverAffectNavigation(false);
	CollisionComponent->bDynamicObstacle = true;

	// RootComponent Transform�� ���� ������Ʈ�̸� �������� ĳ������ ��ġ�� ���Ǹ� �����ϴµ�
	// �߿��� ������ �Ѵ�.
	// USceneComponent�� ��ӹ޴� ������Ʈ���� ��Ʈ ������Ʈ�� �ɼ� �ִ�.
	RootComponent = CollisionComponent;

	// �⺻���� �̵��� �����ϴµ�
	// ���߿� �߰� ������ ���ٵ�
	
	// Actor 
	// Pawn
	// Character <= �� ���� ����� �ʿ��ϴ�.
	//              �̵��� ���õ� ��������� �� ���� �κ��� Ȯ���غ��� �ֽ��ϴ�.
	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(AFreeCameraPawn::MovementComponentName);
	MovementComponent->UpdatedComponent = CollisionComponent;

	// �������� ��Ʈ��Ʈ�� ����
	// ������ ���ҽ��� �ε��ϴ� ����� �����ְ� �ֽ��ϴ�.
	// �ε��� �ؼ�
	// �� ���Ǿ� �Ž��� ��������� �մϴ�.
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh;
		FConstructorStatics()
			: SphereMesh(TEXT("/Engine/EngineMeshes/Sphere")) {}
	};

	static FConstructorStatics ConstructorStatics;

	MeshComponent = CreateOptionalDefaultSubobject<UStaticMeshComponent>(AFreeCameraPawn::MeshComponentName);
	if (MeshComponent)
	{
		MeshComponent->SetStaticMesh(ConstructorStatics.SphereMesh.Object);
		MeshComponent->AlwaysLoadOnClient = true;
		MeshComponent->AlwaysLoadOnServer = true;
		MeshComponent->bOwnerNoSee = true;
		MeshComponent->bCastDynamicShadow = true;
		MeshComponent->bAffectDynamicIndirectLighting = false;
		MeshComponent->bAffectDistanceFieldLighting = false;
		MeshComponent->bVisibleInRayTracing = false;
		MeshComponent->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		MeshComponent->SetupAttachment(RootComponent);
		MeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
		const float Scale = CollisionComponent->GetUnscaledSphereRadius() / 160.f; // @TODO: hardcoding known size of EngineMeshes.Sphere. Should use a unit sphere instead.
		MeshComponent->SetRelativeScale3D(FVector(Scale));
		MeshComponent->SetGenerateOverlapEvents(false);
		MeshComponent->SetCanEverAffectNavigation(false);
	}

	// This is the default pawn class, we want to have it be able to move out of the box.
	bAddDefaultMovementBindings = true;

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

}

// Called when the game starts or when spawned
void AFreeCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFreeCameraPawn::Tick(float DeltaTime)
{
	// �𸮾��� �������� ����ε�
	// �θ�Ŭ������ ���մϴ�.
	// �𸮾� ������ ����ϰ� Ŭ�������� �ʹ� ���� �����ϱ� ������
	// �θ�Ŭ������ ã�ų� �ϴ°͵� ��Ʈ������ �ȴ�.
	// �׷��� �𸮾� ���� ��ü�� �����Ϸ��� ���ؼ�
	// Super�� �θ�Ŭ������ ����ǵ��� ������ذ��̴�.
	// ��� �߳���?
	// �𸮾��� �˾Ƽ� �߰���.
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFreeCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	static bool bBindingsAdded = false;
	if (!bBindingsAdded)
	{
		bBindingsAdded = true;

		// Ű�� ���� ���ǳ����� �Լ�
		// �����̽� Ű�� �����ٰ� ġ�ڽ��ϴ�.
		// ���� ������ �ν��Ѵ�.
		// �����̽� Ű�� ������ 
		// �ε�â�� ���ٰ� ��

		// UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Jump", EKeys::SpaceBar, 1.f));
		// UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Loading_End", EKeys::SpaceBar, 1.f));

		// ���������� ������ üũ�ϰ� ���� Ű��
		// �̵����� ��� 
		// UPlayerInput::AddEngineDefinedAxisMapping
		
		// �ѹ� ������ �׸��� ���ٸ� üũ�ϰ� �������� �ֽ��ϴ�.
		// ��ų
		// UPlayerInput::AddEngineDefinedActionMapping
		

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::W, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveForward", EKeys::S, -1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::A, -1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveRight", EKeys::D, 1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::E, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_MoveUp", EKeys::Q, -1.f));

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_Turn", EKeys::MouseX, 1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_LookUp", EKeys::MouseY, -1.f));

		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Test_Move", EKeys::Y));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Cursor_Off", EKeys::LeftMouseButton));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Cursor_On", EKeys::RightMouseButton));
	}

	// �󸶳� ���������� ���������� ���� ������ ���ϰ� �����ٴ� üũ�ؾ��Ҷ��� �����ϴ�.
	// ���� ���� Ű�� �ԷµǾ����� 
	PlayerInputComponent->BindAxis("DefaultPawn_MoveForward", this, &AFreeCameraPawn::MoveForward);
	PlayerInputComponent->BindAxis("DefaultPawn_MoveRight", this, &AFreeCameraPawn::MoveRight);
	PlayerInputComponent->BindAxis("DefaultPawn_MoveUp", this, &AFreeCameraPawn::MoveUp_World);
	PlayerInputComponent->BindAxis("DefaultPawn_Turn", this, &AFreeCameraPawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("DefaultPawn_LookUp", this, &AFreeCameraPawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Cursor_Off", EInputEvent::IE_Pressed, this, &AFreeCameraPawn::Mouse_Off);
	PlayerInputComponent->BindAction("Cursor_On", EInputEvent::IE_Pressed, this, &AFreeCameraPawn::Mouse_On);

	FInputModeGameOnly InputMode;
	GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
}

void AFreeCameraPawn::Move_Test() 
{
	// Controller->GetControlRotation();
	// ���� ���� ȸ�� ��Ŀ� ���õ� ����� ���ɴϴ�.

	// ������ �⺻������ 
	// ũ��
	
	// �𸮾��� ���ϱ���
	// ��ġ
	// ȸ��

	// ���ϱ����� �ᱹ Transform������� �ϰ�
	// ��κ��� ��������
	// transform�̶�� �̸����� �����ǰ� �������̴�.
	// �ٸ����� ������
	// ��ǥ���� ������ ����Ƽ�� �𸮾��� transform�� ���ؼ� �����ǰ� �ֽ��ϴ�.

	// SetActorLocation({1000.0f, 0.0f, 0.0f});

	// Transform
	// GetTransform().TransformPosition({ 1000.0f, 0.0f, 0.0f });
	

	// �����̳� ���� ���� => ��������
	// ���ϱ����� ������ ��ġ�� �������� ���. 

	

	//FRotator const ControlSpaceRot = Controller->GetControlRotation();
	//AddMovementInput({100.0f, 0.0f, 0.0f}, 1.0f);
	// LogTemp �з�
	UE_LOG(ClientLog, Log, TEXT("Key Input"));
}

void AFreeCameraPawn::MoveForward(float Val) 
{
	// Val�� Ű�� ���������� 0�� �ƴ� ���� ���´�.
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();
			// AddMovementInput({100.0F, 0.0F, 0.0F}, 1.0f);
			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Val);
		}
	}
}

void AFreeCameraPawn::MoveRight(float Val)
{
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), Val);
		}
	}
}

void AFreeCameraPawn::MoveUp_World(float Val)
{
	if (Val != 0.f)
	{
		AddMovementInput(FVector::UpVector, Val);
	}
}

void AFreeCameraPawn::Mouse_On() 
{
	FInputModeUIOnly InputMode;
	GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
}

void AFreeCameraPawn::Mouse_Off() 
{
	FInputModeGameOnly InputMode;
	GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
}