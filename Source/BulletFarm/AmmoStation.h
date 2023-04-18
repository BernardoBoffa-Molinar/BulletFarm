// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReactToInteractInterface.h"
#include "GameData.h"
#include "AmmoStation.generated.h"

UCLASS()
class BULLETFARM_API AAmmoStation : public AActor, public IReactToInteractInterface
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere)
	TEnumAsByte<BulletType> ammoType;

	// Sets default values for this actor's properties
	AAmmoStation();
	virtual void OnInteract() override;

};
