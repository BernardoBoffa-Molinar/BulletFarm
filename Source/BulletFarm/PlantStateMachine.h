// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantState.h"
#include "PlantStateMachine.generated.h"

UCLASS()
class BULLETFARM_API APlantStateMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantStateMachine();

private:
	// Bare State of Plant State Machine
	IPlantState* BareState;
	// Growing State of Plant State Machine
	IPlantState* GrowingState;
	// Complete State of Plant State Machine
	IPlantState* CompleteState;
	// Need Mud State of Plant State Machine
	IPlantState* NeedMudState;
	// Need Water State of Plant State Machine
	IPlantState* NeedWaterState;
	// Need Sun State of Plant State Machine
	IPlantState* NeedSunState;
	// Need Manure State of Plant State Machine
	IPlantState* NeedManureState;
	// Need Pesticide State of Plant State Machine
	IPlantState* NeedPesticideState;

	// CurrentState
	IPlantState* CurrentState;


	// plant score of growing
	int GrowingScore =0;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// initialize all plant states
	void Initialize();
	
	
};
