// Fill out your copyright notice in the Description page of Project Settings.
#include "Boule.h"

#include "Cours01Pratique/Cours01PratiqueCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABoule::ABoule()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABoule::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABoule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/*
void ABoule::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
                       bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                       const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	ACours01PratiqueCharacter* myPlayer = Cast<ACours01PratiqueCharacter>(
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (!IsValid(myPlayer))return;

	if (Other == myPlayer)
	{
		myPlayer->keys++;
		FString keyCount = FString::Printf(TEXT("Keys: %d"), myPlayer->keys);
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, keyCount);
		Destroy();
	}

}
*/

void ABoule::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	auto Player = Cast<ACours01PratiqueCharacter>(OtherActor);
    	if (Player != nullptr)
    	{
    		Player->keys++;
    		FString keyCount = FString::Printf(TEXT("Keys: %d"), Player->keys);
    		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, keyCount);
    		Destroy();
    	}
}
