// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

UCLASS()
class PAPERBOY_API AGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoal();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	class UBoxComponent* BoxComponent;

	UFUNCTION(BlueprintImplementableEvent)
		void OnReach();


	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
