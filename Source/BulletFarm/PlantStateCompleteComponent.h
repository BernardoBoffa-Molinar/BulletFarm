// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantState.h"
#include "Components/ActorComponent.h"
#include "PlantStateCompleteComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BULLETFARM_API UPlantStateCompleteComponent : public UActorComponent, public IPlantState
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlantStateCompleteComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class APlantStateMachine* PlantStateMachine;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetPlantStateMachine(APlantStateMachine* Plant) override;
	virtual void OnStateEnter() override;
	virtual void OnStateExit() override;
	virtual void OnInteract() override;
	virtual void OnBulletCollision(float BulletType) override;
	virtual void NeedSatisfied() override;
	virtual FString NameToString() override;
};
