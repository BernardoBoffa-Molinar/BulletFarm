// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateCompleteComponent.h"

// Sets default values for this component's properties
UPlantStateCompleteComponent::UPlantStateCompleteComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlantStateCompleteComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlantStateCompleteComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UPlantStateCompleteComponent::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void UPlantStateCompleteComponent::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered Complete Plant State"));
}

void UPlantStateCompleteComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited Complete Plant State"));

}

void UPlantStateCompleteComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with Complete Plant State"));

}

void UPlantStateCompleteComponent::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with  Complete Plant State"));

}

void UPlantStateCompleteComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of Complete Plant State Satisfied"));
}

FString UPlantStateCompleteComponent::NameToString()
{
	return "Complete Plant State";
}

