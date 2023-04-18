// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class BULLETFARM_API GameData {
private:
	GameData() {}

	int32 score;
	TArray<int32> ammoCounts;

	UPROPERTY(EditAnyWhere)
	int32 ammoCapacity = 5;


public:
	UFUNCTION(BlueprintCallable)
	void TryFireAmmo(TEnumAsByte<BulletType> bulletType, bool& hasFired);

	UFUNCTION(BlueprintCallable)
	void RefillAmmo(TEnumAsByte<BulletType> bulletType);


	UFUNCTION(BlueprintCallable)
	void AddScore(int32 deltaScore);


};
