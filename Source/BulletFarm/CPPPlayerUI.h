// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BulletFarmCharacter.h"
#include "CPPPlayerUI.generated.h"

/**
 * 
 */
UCLASS()
class BULLETFARM_API UCPPPlayerUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category ="PlayerInfo")
	ABulletFarmCharacter* MyPlayer;

	UFUNCTION(BlueprintCallable)
	void SetMyPlayer(ABulletFarmCharacter* player);
};
