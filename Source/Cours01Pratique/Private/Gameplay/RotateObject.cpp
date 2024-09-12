// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateObject.h"

// Sets default values
ARotateObject::ARotateObject()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARotateObject::BeginPlay()
{
	Super::BeginPlay();
	// CurrentRotation = GetActorRotation();
	// RotateObject();	
}

// Called every frame
void ARotateObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FRotator NewRotation = FRotator();
	NewRotation.Yaw += 10.f * DeltaTime;

	AddActorLocalRotation(NewRotation);
}

void ARotateObject::RotateObject()
{
//	
}
