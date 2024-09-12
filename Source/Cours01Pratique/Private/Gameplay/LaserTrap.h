// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaserTrap.generated.h"

UCLASS()
class ALaserTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserTrap();
	int32 TimerCount =0;
	FTimerHandle TimerHandle;
	bool AsMove = false;
	
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Laser;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Base;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void OnTimer();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
