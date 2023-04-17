// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantState.h"
#include "GrowingPlantState.generated.h"

UCLASS()
class BULLETFARM_API AGrowingPlantState : public AActor, public  IPlantState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrowingPlantState();
private:
	UPROPERTY()
	class APlantStateMachine* PlantStateMachine;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetPlantStateMachine(APlantStateMachine* Plant) override;
	virtual void OnStateEnter() override;
	virtual void OnStateExit() override;
	virtual void OnInteract() override;
	virtual void OnBulletCollision(float BulletType) override;
	virtual void NeedStatisfied() override;
	virtual FString NameToString() override;
};
