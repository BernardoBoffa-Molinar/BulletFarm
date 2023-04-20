// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BulletType.h"
//#include "BulletTemplate.h"
#include "BulletFarmGameMode.generated.h"

UCLASS(minimalapi)
class ABulletFarmGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABulletFarmGameMode();

	//UPROPERTY(EditAnywhere)
	//TArray<FBulletTemplate> bulletTemplates;
};



