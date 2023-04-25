// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantStateMachine.h"
#include "Blueprint/UserWidget.h"
#include "PlantFeedbackWidget.generated.h"


/**
 * 
 */
UCLASS()
class BULLETFARM_API UPlantFeedbackWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category ="PlantInfo")
	APlantStateMachine* MyPlant;

	UFUNCTION(BlueprintCallable)
	void SetMyPlantStateMachine(APlantStateMachine* plant);
	
};
