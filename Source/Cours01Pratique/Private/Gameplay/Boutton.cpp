// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Boutton.h"

// Sets default values
ABoutton::ABoutton()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	openDoor = false;
}

// Called when the game starts or when spawned
void ABoutton::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABoutton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABoutton::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (OtherActor->IsValidLowLevel())
	{
		openDoor = true;

		FString isHit = TEXT("IsHit");
		GEngine->AddOnScreenDebugMessage(-3, 5, FColor::Green, isHit);
	}
}
