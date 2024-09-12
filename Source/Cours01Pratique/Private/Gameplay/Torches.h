// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TorcheDoor.h"
#include "GameFramework/Actor.h"
#include "Torches.generated.h"

UCLASS()
class ATorches : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATorches();
	UPROPERTY(EditAnywhere, category = "torches Value")
	int ValueForSequence;

	UPROPERTY(editAnywhere, category = "Door")
	ATorcheDoor* Door;
	bool DoOnce = false;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	                       bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
	                       const FHitResult& Hit) override;
};
