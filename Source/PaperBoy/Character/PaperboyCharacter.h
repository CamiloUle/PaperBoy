// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PaperboyCharacter.generated.h"

UCLASS()
class PAPERBOY_API APaperboyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APaperboyCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class UBoxComponent* BoxComponent;

	void UpdateMovement(FVector WorldDirection);
	
	FVector2D InputMovement;

	void CreateProjectile(bool bIsShootingRight);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf <class AProjectile> PaperClass;

	UPROPERTY(Transient)
	float CharacterSpeed = 0.75;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

};
