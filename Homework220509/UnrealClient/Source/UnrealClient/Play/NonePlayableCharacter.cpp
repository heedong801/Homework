// Fill out your copyright notice in the Description page of Project Settings.


#include "NonePlayableCharacter.h"
#include "ClientAIController.h"

ANonePlayableCharacter::ANonePlayableCharacter() 
	: Super()
{
	AIControllerClass = AClientAIController::StaticClass();
}