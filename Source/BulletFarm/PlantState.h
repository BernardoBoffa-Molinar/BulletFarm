// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlantState.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlantState : public UInterface
{
	GENERATED_BODY()
};

/**
 *  ADD BULLET TYPE ENUM FROM DAVID
 */
class BULLETFARM_API IPlantState
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual void SetPlantStateMachine(class APlantStateMachine* Plant) =0;
	virtual void OnStateEnter()=0;
	virtual void OnStateExit()=0;
	virtual void OnInteract() =0;
	// REPLACE WITH BULLET TYPE ENUM
	virtual void OnBulletCollision(float BulletType ) =0 ;
	virtual void NeedSatisfied() = 0;
	virtual FString NameToString()=0;

};
