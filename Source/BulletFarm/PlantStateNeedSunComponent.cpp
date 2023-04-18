// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateNeedSunComponent.h"
#include "PlantStateMachine.h"
// Sets default values for this component's properties
UPlantStateNeedSunComponent::UPlantStateNeedSunComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlantStateNeedSunComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlantStateNeedSunComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UPlantStateNeedSunComponent::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void UPlantStateNeedSunComponent::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Orange, TEXT("Entered NeedSun Plant State"));

}

void UPlantStateNeedSunComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Orange, TEXT("Exited NeedSun Plant State"));

}

void UPlantStateNeedSunComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Orange, TEXT("Intereacted with NeedSun Plant State"));

}

void UPlantStateNeedSunComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Orange, TEXT("Bullet Colision with NeedSun Plant State"));

	if( BulletType == BulletType::Sun)
	{
		NeedSatisfied();
	}
	else
	{
		// inform player the plant need Sun
		//Interact in BP
		PlantStateMachine->DecreasedPlantGrowingScore();
	}
}

void UPlantStateNeedSunComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Orange, TEXT("Needs of NeedSun Plant State Satisfied"));
	PlantStateMachine->IncreasedPlantGrowingScore();
	PlantStateMachine->SetState(PlantStateMachine->GetGrowingPlantState());

}

FString UPlantStateNeedSunComponent::NameToString()
{
	return "NeedSun Plant State";
}

