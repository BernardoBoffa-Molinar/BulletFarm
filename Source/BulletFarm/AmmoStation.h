// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReactToInteractInterface.h"

#include "AmmoStation.generated.h"

UCLASS()
class BULLETFARM_API AAmmoStation : public AActor, public IReactToInteractInterface
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere)
	TEnumAsByte<BulletType> ammoType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* fireSound;

	// Sets default values for this actor's properties
	AAmmoStation();

	UFUNCTION(BlueprintNativeEvent)
	void OnInteract(); virtual void OnInteract_Implementation() override;

};
