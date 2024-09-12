// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TorcheDoor.generated.h"

UCLASS()
class ATorcheDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorcheDoor();

	UPROPERTY(EditAnywhere ,Category = "Sequence")
	TArray<int> Sequence;
	int CurrentIndex =0;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void CheckSequence(int sequence);
};
