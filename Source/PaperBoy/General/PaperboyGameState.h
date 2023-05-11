// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PaperboyGameState.generated.h"

/**
 * 
 */
UCLASS()
class PAPERBOY_API APaperboyGameState : public AGameState
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	int32 HousesImpactedNum;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	int32 MailBoxImpactedNum;
	
	
public:
	bool IsImpacted = false;
	
};
