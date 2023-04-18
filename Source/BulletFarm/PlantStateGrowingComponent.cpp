// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateGrowingComponent.h"

// Sets default values for this component's properties
UPlantStateGrowingComponent::UPlantStateGrowingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlantStateGrowingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlantStateGrowingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UPlantStateGrowingComponent::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void UPlantStateGrowingComponent::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered Growing Plant State"));

}

void UPlantStateGrowingComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited Growing Plant State"));

}

void UPlantStateGrowingComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with Growing Plant State"));

}

void UPlantStateGrowingComponent::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with Growing Plant State"));

}

void UPlantStateGrowingComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of Growing Plant State Satisfied"));

}

FString UPlantStateGrowingComponent::NameToString()
{
	return "Growing Plant State";
}

