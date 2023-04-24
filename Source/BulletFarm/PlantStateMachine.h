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
	// CurrentState
	IPlantState* CurrentState;
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

	

    

protected:
	// plant score of growing
	UPROPERTY(BlueprintReadOnly, Category ="PlantInfo")
	int PlantScore =0;

	float PlantTimer =  0.0f;
	float PlantCooldown =  5.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	IPlantState* GetCurrentState();
	IPlantState* GetBarePlantState();
	IPlantState* GetGrowingPlantState();
	IPlantState* GetCompletePlantState();
	IPlantState* GetNeedMudPlantState();
	IPlantState* GetNeedWaterPlantState();
	IPlantState* GetNeedManurePlantState();
	IPlantState* GetNeedSunPlantState();
	IPlantState* GetNeedPesticidePlantState();

	void IncreasedPlantGrowingScore();
	void DecreasedPlantGrowingScore();
	void CreatePlantNeed();
	
	void SetState(IPlantState* stateToSet);
protected:
	// initialize all plant states
	void Initialization();
	FString GetCurrentStateName();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnBulletHit(TEnumAsByte<BulletType>& typeofBullet); virtual void OnBulletHit_Implementation(TEnumAsByte<BulletType>& typeofBullet);
	
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



	UFUNCTION(BlueprintImplementableEvent)
	void ChangePlant();
};
