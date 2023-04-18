// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateNeedWaterComponent.h"

// Sets default values for this component's properties
UPlantStateNeedWaterComponent::UPlantStateNeedWaterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlantStateNeedWaterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlantStateNeedWaterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlantStateNeedWaterComponent::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void UPlantStateNeedWaterComponent::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered NeedWater Plant State"));

}

void UPlantStateNeedWaterComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited NeedWater Plant State"));

}

void UPlantStateNeedWaterComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with NeedWater Plant State"));

}

void UPlantStateNeedWaterComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with NeedWater Plant State"));

}

void UPlantStateNeedWaterComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of NeedWater Plant State Satisfied"));

}

FString UPlantStateNeedWaterComponent::NameToString()
{
	return "NeedWater Plant State";
}
