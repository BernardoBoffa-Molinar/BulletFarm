// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReactToInteractInterface.h"
#include "BulletFarmGameMode.h"
#include "AmmoStation.generated.h"

UCLASS()
class BULLETFARM_API AAmmoStation : public AActor, public IReactToInteractInterface
{
	GENERATED_BODY()
	
private:
	ABulletFarmGameMode* gameMode;

public:	

	UPROPERTY(EditAnywhere)
	TEnumAsByte<BulletType> ammoType;

	// Sets default values for this actor's properties
	AAmmoStation();
	virtual void OnInteract() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
