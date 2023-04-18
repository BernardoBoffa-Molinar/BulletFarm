// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantState.h"
#include "ReactToBulletInterface.h"
#include "PlantStateMachine.generated.h"

UCLASS()
class BULLETFARM_API APlantStateMachine : public AActor, public IReactToBulletInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantStateMachine();

private:
	// Bare State of Plant State Machine
	
	IPlantState* BareState;
	// Growing State of Plant State Machine
	class 
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
	int PlantGrowingScore =0;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FString GetCurrentStateName();
	IPlantState* GetCurrentState();
	IPlantState* GetBarePlantState();
	IPlantState* GetGrowingPlantState();
	IPlantState* GetCompletePlantState();
	IPlantState* GetNeedMudPlantState();
	IPlantState* GetNeedWaterPlantState();
	IPlantState* GetNeedManurePlantState();
	IPlantState* GetNeedSunPlantState();
	IPlantState* GetNeedPesticidePlantState();
	
	// initialize all plant states
	void Initialization();
	void SetState(IPlantState* stateToSet);
	
	// overide IReactto On Bullet hit Interface function
	virtual void OnBulletHit(TEnumAsByte<BulletType> type) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UPlantStateBareComponent* BareComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UPlantStateGrowingComponent* GrowingComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UPlantStateCompleteComponent* CompleteComponent;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UPlantStateNeedWaterComponent* NeedWaterComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UPlantStateNeedMudComponent* NeedMudComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UPlantStateNeedManureComponent* NeedManureComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UPlantStateNeedPesticideComponent* NeedPesticideComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UPlantStateNeedSunComponent* NeedSunComponent;

};
