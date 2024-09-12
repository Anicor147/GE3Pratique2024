// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/TorcheDoor.h"

// Sets default values
ATorcheDoor::ATorcheDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATorcheDoor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATorcheDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATorcheDoor::CheckSequence(int sequence)
{
		if (sequence == Sequence[CurrentIndex])
		{
			UE_LOG(LogTemp, Log, TEXT("Current index before: %d"), CurrentIndex);
			CurrentIndex++;
			UE_LOG(LogTemp, Log, TEXT("Current index After: %d"), CurrentIndex);
			if (CurrentIndex >= Sequence.Max())
			{
				Destroy();
			}
		}
}
