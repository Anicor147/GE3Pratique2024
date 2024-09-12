// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

#include "Cours01Pratique/Cours01PratiqueCharacter.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ADoor::ADoor(): bOpenWithButton(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	myPlayer = Cast<ACours01PratiqueCharacter>(
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OpenDoor();
}

void ADoor::OpenDoor()
{
	if (myPlayer->keys == 3 && !bOpenWithButton)
	{
		Destroy();
	}
}

void ADoor::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
                      bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                      const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (bOpenWithButton)
	{
		Destroy();
	}
}
