// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlantState.h"
#include "PlantStateNeedWaterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BULLETFARM_API UPlantStateNeedWaterComponent : public UActorComponent, public IPlantState
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlantStateNeedWaterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	class APlantStateMachine* PlantStateMachine;
	
public:	
	virtual void SetPlantStateMachine(APlantStateMachine* Plant) override;
	virtual void OnStateEnter() override;
	virtual void OnStateExit() override;
	virtual void OnInteract() override;
	virtual void OnBulletCollision(BulletType BulletType) override;
	virtual void NeedSatisfied() override;
	virtual FString NameToString() override;
};
