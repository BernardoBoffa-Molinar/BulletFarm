// Fill out your copyright notice in the Description page of Project Settings.


#include "GameData.h"

void GameData::TryFireAmmo(TEnumAsByte<BulletType> bulletType, bool& hasFired) {
	uint8 bulletIndex = (uint8) bulletType;
	hasFired = ammoCounts[bulletIndex] > 0;
	if (hasFired) ammoCounts[bulletIndex]--;	
}

void GameData::RefillAmmo(TEnumAsByte<BulletType> bulletType) {
	uint8 bulletIndex = (uint8) bulletType;
	ammoCounts[bulletIndex] = ammoCapacity;
}

void GameData::AddScore(int32 deltaScore) {
	score += deltaScore;
}