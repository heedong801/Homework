// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageComponent.h"
#include <Memory>
#include <functional>
#include "Handler/HandlerHeader.h"
#include "../Global/ClientGameInstance.h"


// Sets default values for this component's properties
UMessageComponent::UMessageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void UMessageComponent::BeginPlay()
{
	Super::BeginPlay();

	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetOwner()->GetGameInstance());

	CheckHandler(Dis,Inst, GetWorld());

	// ...
	
}


// Called every frame
void UMessageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);



	// ���⼭ ƽ�� ����.

	// [���ú� ������ �޼����� �ö����� ���ϵǼ� ������ �Ѵ�.]
	// ���⼭ ���ڱ� ������ ��ġ�� �ٲ�.
	// �޾Ƽ� �޼����� ���常 �� �����ϴ�.
	// �׾� ���⸸ �ϴ� �̴ϴ�.


	// �������� ����....
	// �޼����� �� �����ϴ�.
	// �ѹ��� ���� �����ϴ�.
	// �𸮾��� queue�� �̿��ؾ� �մϴ�.
	// �׾ȿ��� 
	// 
	// 
	// 
	// [�𸮾� ���� ������ ���͵��� �����̰� �� �׷��� �ִ�.]
	// �����δ� �������� �ض�.
	// ���⼭ ������ �ϰ� �־���.


	// ���ú� �����忡�� ���͸� �����̷��� �ϰų�

	if (false == GetOwner()->IsValidLowLevel())
	{
		return;
	}


	UClientGameInstance* Inst = Cast<UClientGameInstance>(GetOwner()->GetGameInstance());

	while (false == Inst->IsEmptyMessage())
	{

		std::shared_ptr<GameServerMessage> Message = Inst->PopMessage();

		if (nullptr == Message)
		{
			continue;
		}

		MessageHandler MsgHandler;

		Dis.GetHandler(Message->GetId(), MsgHandler);

		if (nullptr == MsgHandler)
		{
			return;
		}

		// �׹������ ���� �ǰ��.
		// ��������Ʈ���� �� ������Ʈ���� ������ ƽ�� ������ ���ݾƿ�?
		MsgHandler(Message);
		// Inst->get
	}


	// ...
}

