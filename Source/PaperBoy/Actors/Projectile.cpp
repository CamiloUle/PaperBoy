// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectile.h"
#include "Actors/House.h"
#include "Actors/Mailbox.h"
#include "General/PaperBoyGameState.h"
#include "Components/SphereComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlapBegin);
}



// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + (MovementDirection * Speed * DeltaTime));
}

void AProjectile::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this) 
	{
		AHouse* Impactedhouse = Cast<AHouse>(OtherActor);
		if (Impactedhouse) 
		{
			APaperboyGameState* PaperBoyGameState = GetWorld()->GetGameState<APaperboyGameState>();
			if (PaperBoyGameState) 
			{
				PaperBoyGameState->HousesImpactedNum += 1;
				Impactedhouse->OnImpact();
			}
			Destroy();
		}

		AMailbox* ImpactMailbox = Cast<AMailbox>(OtherActor);
		if (ImpactMailbox)
		{
			APaperboyGameState* PaperBoyGameState = GetWorld()->GetGameState<APaperboyGameState>();
			if (PaperBoyGameState && !ImpactMailbox->bIsImpacted)
			{
				PaperBoyGameState->MailBoxImpactedNum += 1;
				ImpactMailbox->bIsImpacted = true;
				ImpactMailbox->OnImpact();
				//ImpactMailbox->Destroy();
			}
			Destroy();
		}
	}
}


