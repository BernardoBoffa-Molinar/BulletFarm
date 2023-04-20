// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReactToBulletInterface.h"
#include "BulletHitTest.generated.h"

UCLASS()
class BULLETFARM_API ABulletHitTest : public AActor, public IReactToBulletInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletHitTest();

	UFUNCTION(BlueprintNativeEvent)
	void OnBulletHit(TEnumAsByte<BulletType>& type); virtual void OnBulletHit_Implementation(TEnumAsByte<BulletType>& type);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
