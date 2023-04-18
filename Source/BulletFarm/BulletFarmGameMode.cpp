// Copyright Epic Games, Inc. All Rights Reserved.

#include "BulletFarmGameMode.h"
#include "BulletFarmCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABulletFarmGameMode::ABulletFarmGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}