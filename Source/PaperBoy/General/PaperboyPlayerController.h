// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaperboyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PAPERBOY_API APaperboyPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	void SetupInputComponent() override;
	virtual void BeginPlay() override;

	void InputMovementX(float Value);
	void InputMovementY(float Value);

	void OnShootLeft();
	void OnShootRight();

	FVector2D InputMovement = FVector2D::ZeroVector;

	class APaperboyCharacter* CharacterControlled;


	UPROPERTY(Transient)
	class APaperboyGameState* PaperboyGameState;


};
