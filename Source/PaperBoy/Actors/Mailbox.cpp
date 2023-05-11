// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Mailbox.h"
#include "Actors/Projectile.h" 
#include "General/PaperBoyGameState.h"
#include "Components/SphereComponent.h"

// Sets default values
AMailbox::AMailbox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMailbox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMailbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMailbox::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if (OtherActor && OtherActor != this)
	{
		AProjectile* ImpactedMailBox = Cast<AProjectile>(OtherActor);
		if (ImpactedMailBox)
		{
			APaperboyGameState* PaperBoyGameState = GetWorld()->GetGameState<APaperboyGameState>();
			if(PaperBoyGameState)
			{
				Destroy();
			}
		}
	}
}

