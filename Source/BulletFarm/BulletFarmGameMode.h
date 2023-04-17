// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BulletType.h"
#include "BulletFarmGameMode.generated.h"

UCLASS(minimalapi)
class ABulletFarmGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	int32 score;
	TArray<int32> ammoCounts;

	UPROPERTY(EditAnyWhere)
	int32 ammoCapacity = 5;

public:
	ABulletFarmGameMode();

	UFUNCTION(BlueprintCallable)
	void TryFireAmmo(TEnumAsByte<BulletType> bulletType, bool& hasFired);

	UFUNCTION(BlueprintCallable)
	void RefillAmmo(TEnumAsByte<BulletType> bulletType);


	UFUNCTION(BlueprintCallable)
	void AddScore(int32 deltaScore);

};



