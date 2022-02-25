// Fill out your copyright notice in the Description page of Project Settings.


#include "FreeCameraPawn.h"
#include "Components/SphereComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PlayerInput.h"

FName AFreeCameraPawn::MovementComponentName(TEXT("MovementComponent0"));
FName AFreeCameraPawn::CollisionComponentName(TEXT("CollisionComponent0"));
FName AFreeCameraPawn::MeshComponentName(TEXT("MeshComponent0"));

// Sets default values
AFreeCameraPawn::AFreeCameraPawn()
{
	// 생성자에서 작성되는 코드는 엔진에서 보일 엑터의 기본 구조를 정의내릴수 있습니다.
	// 초기화와 대입은 엄청나게 다른 개념이죠
	// 언리얼에서 어떠한 블루프린트 클래스를 만들때
	// 그녀석을 처음 한번 새롭게 생성합니다.

	// 이걸 CDO라고 합니다.
	// CreateDefaultObject

	// 상속의 단점
	// 부모클래스의 쓸모없는 기능들도 자식들이 물려받는다.
	// 어? 나는 대화기능이 필요없는데?
	// 어? 나는 벽에 안부딪치는데?
	// 모두가 이건 쓰겠지....
	// => 안쓰는 기능들도 강제적으로 상속받는 경우가 많아지게 된다.
	
	// 기능 자체를 클래스로 만들고
	// 그 기능를 들고 있으면 기능할수 있다.
	// 이걸 Component(내가 정하는 기능)라고 하는 부모클래스를 통해서
	// 하나로 관리하는것을 컴포넌트 구조라고 합니다.
	// std::list<Component*>

	// 대화를 할수 있다.
	// class Talk : pubic Component
	// class Jump : pubic Component

	// 학생들이 주의해야할 점은
	// 마치. 상속 VS 컴포넌트(상속을 하면 안되)
	// 둘은 상호 보환 적인 관계이고.
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// 충돌관련인데
	// 충돌 그자체를 Damage라
	SetCanBeDamaged(true);

	SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	bReplicates = true;
	// 언리얼 서버용 다른 서버가 들어오면 

	NetPriority = 3.0f;

	BaseEyeHeight = 0.0f;
	bCollideWhenPlacing = false;
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// CreateDefaultSubobject 블루프린트가 생성되기전
	// 이 클래스를 사용하는 블루프린트들의 기본기능을 생성자에서 지정해줄수 있다.
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(AFreeCameraPawn::CollisionComponentName);
	CollisionComponent->InitSphereRadius(35);

	// 충돌 그룹
	// 몬스터 총알 
	// 몬스터 그룹 
	// 클라와 서버중 누구의 의사결정이 더 우선될것인가? 
	// 클라가 내리는게 많아지면 핵을 막을수가 없게되는 것이고
	// 서버가 모든 결정을 내리면
	// 액션성이 죽게 됩니다.
	// 로아가 좀 액션성이 뛰어난 편이죠? 채널을 나누거나
	// 와우 한자리에 100명이 모였어
	// 안겹치는 게임은 대부분 클라가 합니다.
	// 서버가 어떻게 만들어졌을까를 잘 생각해보면
	// 어느 부분이 클라가 처리하고 어느부분이 서버가 처리하는지 생각해볼수 있습니다.
	// 선생님도 Pve만 한다.
	CollisionComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	CollisionComponent->SetShouldUpdatePhysicsVolume(true);
	CollisionComponent->SetCanEverAffectNavigation(false);
	CollisionComponent->bDynamicObstacle = true;

	// RootComponent Transform을 가진 컴포넌트이며 씬에서의 캐릭터의 위치나 부피를 결정하는데
	// 중요한 역할을 한다.
	// USceneComponent를 상속받는 컴포넌트만이 루트 컴포넌트가 될수 있다.
	RootComponent = CollisionComponent;

	// 기본적인 이동에 관여하는데
	// 나중에 추가 설명을 할텐데
	
	// Actor 
	// Pawn
	// Character <= 더 많은 기능이 필요하다.
	//              이동에 관련된 기능이지만 더 많은 부분을 확인해볼게 있습니다.
	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(AFreeCameraPawn::MovementComponentName);
	MovementComponent->UpdatedComponent = CollisionComponent;

	// 지역에서 스트럭트를 만들어서
	// 엔진의 리소스를 로딩하는 방법을 보여주고 있습니다.
	// 로딩을 해서
	// 그 스피어 매쉬를 세팅해줘야 합니다.
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
	// 언리얼이 재정의한 기능인데
	// 부모클래스를 말합니다.
	// 언리얼 엔진은 방대하고 클래스들이 너무 많고 복잡하기 때문에
	// 부모클래스를 찾거나 하는것도 스트레스가 된다.
	// 그래서 언리얼 엔진 자체의 컴파일러를 통해서
	// Super는 부모클래스로 연결되도록 만들어준것이다.
	// 어떻게 했나요?
	// 언리얼이 알아서 했겠죠.
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

		// 키를 먼저 정의내리는 함수
		// 스페이스 키를 눌렀다고 치겠습니다.
		// 나는 점프로 인식한다.
		// 스페이스 키를 누르면 
		// 로딩창을 끈다고 볼

		// UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Jump", EKeys::SpaceBar, 1.f));
		// UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("Loading_End", EKeys::SpaceBar, 1.f));

		// 지속적으로 누르는 체크하고 싶은 키와
		// 이동같은 경우 
		// UPlayerInput::AddEngineDefinedAxisMapping
		
		// 한번 눌렀다 그리고 땠다를 체크하고 싶을때가 있습니다.
		// 스킬
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

	// 얼마나 지속적으로 오래눌렀고 세게 눌렀다 약하게 눌렀다는 체크해야할때가 많습니다.
	// 정의 내린 키가 입력되었을대 
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
	// 현재 폰의 회전 행렬에 관련된 기능을 얻어옵니다.

	// 서버는 기본적으로 
	// 크기
	
	// 언리얼은 기하구조
	// 위치
	// 회전

	// 기하구조란 결국 Transform구조라고 하고
	// 대부분의 엔진에서
	// transform이라는 이름으로 관리되고 있을것이다.
	// 다를수도 있지만
	// 대표적인 엔진인 유니티와 언리얼은 transform을 통해서 관리되고 있습니다.

	// SetActorLocation({1000.0f, 0.0f, 0.0f});

	// Transform
	// GetTransform().TransformPosition({ 1000.0f, 0.0f, 0.0f });
	

	// 질량이나 무게 재질 => 물리구조
	// 기하구조에 영향을 끼치는 물리적인 요소. 

	

	//FRotator const ControlSpaceRot = Controller->GetControlRotation();
	//AddMovementInput({100.0f, 0.0f, 0.0f}, 1.0f);
	// LogTemp 분류
	UE_LOG(LogTemp, Log, TEXT("Key Input"));
}

void AFreeCameraPawn::MoveForward(float Val) 
{
	// Val은 키가 눌렸을때만 0이 아닌 값이 들어온다.
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