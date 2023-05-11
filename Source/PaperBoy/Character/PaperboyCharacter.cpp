//Fill out your copyright notice in the Description page of Project Settings.

#include "Character/PaperboyCharacter.h"
#include "Actors/Projectile.h"
#include "Actors/Goal.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"


// Sets default values
APaperboyCharacter::APaperboyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(RootComponent);

	
}

// Called when the game starts or when spawned
void APaperboyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APaperboyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float AdditionalSpeed = 0.0f;

	if (InputMovement.X > 0.0f) 
	{
		AdditionalSpeed = 0.5f;
	}
	else if (InputMovement.X < 0.0f) 
	{
		AdditionalSpeed = -0.5f;
	}

	AddMovementInput(FVector(CharacterSpeed + AdditionalSpeed, InputMovement.Y,0));
}

// Called to bind functionality to input
void APaperboyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APaperboyCharacter::CreateProjectile(bool bIsShootingRight) 
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.bNoFail = true;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;


	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(PaperClass, GetActorLocation(), FRotator::ZeroRotator, SpawnParams);

	if (bIsShootingRight) 
	{
		Projectile->MovementDirection = FVector(0,1,0);
	}
	else 
	{
		Projectile->MovementDirection = FVector(0, -1, 0);
	}
}



