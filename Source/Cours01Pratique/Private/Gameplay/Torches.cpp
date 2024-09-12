// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Torches.h"

#include "TorcheDoor.h"

// Sets default values
ATorches::ATorches()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATorches::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATorches::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATorches::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
                         bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                         const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (!DoOnce)
	{
		Door->CheckSequence(ValueForSequence);
		DoOnce = true;
	}
}
