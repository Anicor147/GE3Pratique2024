// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/LaserTrap.h"

// Sets default values
ALaserTrap::ALaserTrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Base = CreateDefaultSubobject<UStaticMeshComponent>("Base");
	RootComponent = Base;
	Laser = CreateDefaultSubobject<UStaticMeshComponent>("Laser");
	Laser->AttachToComponent(Base, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ALaserTrap::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALaserTrap::OnTimer, 1.0f, true);
	Base->SetCollisionEnabled(static_cast<ECollisionEnabled::Type>(false));
}

void ALaserTrap::OnTimer()
{
	++TimerCount;
	//UE_LOG(LogTemp, Log, TEXT("Timer Tick: %d"), TimerCount);

	if (!AsMove)
	{
		Laser->AddLocalOffset(FVector(0.0f, 0.0f, -10000.f));
		AsMove = true;
	}


	// Are we done counting?
	if (TimerCount >= 3)
	{
		// Clear the timer handle so it won't keep triggering events
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

		Laser->AddLocalOffset(FVector(0.0f, 0.0f, 10000.f));
		AsMove = false;
		//		UE_LOG(LogTemp, Log, TEXT("Clearing the timer."));
		TimerCount = 0;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALaserTrap::OnTimer, 1.0f, true);
	}
}

void ALaserTrap::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// It's important to keep the call chain on EndPlay or you may end up with serious bugs or crashes
	Super::EndPlay(EndPlayReason);

	// There's a chance your timer is still running when our Actor is destroyed
	// So we need to make sure we clear the timer on EndPlay just in case.
	// This is safe to call even if the timer handle's already been cleared.
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

// Called every frame
void ALaserTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
