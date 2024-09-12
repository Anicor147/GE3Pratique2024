// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cours01PratiqueGameMode.h"
#include "Cours01PratiqueCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACours01PratiqueGameMode::ACours01PratiqueGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
