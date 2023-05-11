// Fill out your copyright notice in the Description page of Project Settings.

#include "General/PaperboyPlayerController.h"
#include "Character/PaperboyCharacter.h"
#include "General/PaperboyGameState.h"

void APaperboyPlayerController::SetupInputComponent() 
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MovementX", this, &APaperboyPlayerController::InputMovementX);
	InputComponent->BindAxis("MovementY", this, &APaperboyPlayerController::InputMovementY);

	InputComponent->BindAction("ShootLeft", IE_Pressed, this, &APaperboyPlayerController::OnShootLeft);
	InputComponent->BindAction("ShootRight", IE_Pressed, this, &APaperboyPlayerController::OnShootRight);
}

void APaperboyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	CharacterControlled = Cast<APaperboyCharacter>(GetPawn());
}

void APaperboyPlayerController::InputMovementX(float Value) 
{
	if (CharacterControlled) 
	{
		CharacterControlled->InputMovement.X = Value;
	}
}

void APaperboyPlayerController::InputMovementY(float Value)
{
	if (CharacterControlled)
	{
		CharacterControlled->InputMovement.Y = Value;
	}
}

void APaperboyPlayerController::OnShootLeft() 
{
	if (CharacterControlled) 
	{
		CharacterControlled->CreateProjectile(false);
	}
}

void APaperboyPlayerController::OnShootRight()
{
	if (CharacterControlled)
	{
		CharacterControlled->CreateProjectile(true);
	}
}

