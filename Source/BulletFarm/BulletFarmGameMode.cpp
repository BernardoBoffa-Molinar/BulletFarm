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

	ammoCounts.Init(3, 0);

}

void ABulletFarmGameMode::TryFireAmmo(TEnumAsByte<BulletType> bulletType, bool& hasFired) {
	uint8 bulletIndex = (uint8) bulletType;
	hasFired = ammoCounts[bulletIndex] > 0;
	if (hasFired) ammoCounts[bulletIndex]--;	
}

void ABulletFarmGameMode::RefillAmmo(TEnumAsByte<BulletType> bulletType) {
	uint8 bulletIndex = (uint8) bulletType;
	ammoCounts[bulletIndex] = ammoCapacity;
}

void ABulletFarmGameMode::AddScore(int32 deltaScore) {
	score += deltaScore;
}