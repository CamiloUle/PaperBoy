// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Goal.h"
#include "Components/BoxComponent.h"
#include "Character/PaperboyCharacter.h"
// Sets default values
AGoal::AGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(RootComponent);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AGoal::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoal::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if (OtherActor && OtherActor != this) 
	{
		APaperboyCharacter* Character = Cast<APaperboyCharacter>(OtherActor);

		if (Character) 
		{
			OnReach();
			Character->CharacterSpeed = 0.f;
		
		}
	}
}

