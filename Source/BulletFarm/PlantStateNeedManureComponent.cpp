// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateNeedManureComponent.h"

// Sets default values for this component's properties
UPlantStateNeedManureComponent::UPlantStateNeedManureComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlantStateNeedManureComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlantStateNeedManureComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



void UPlantStateNeedManureComponent::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void UPlantStateNeedManureComponent::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered NeedManure Plant State"));

}

void UPlantStateNeedManureComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited NeedManure Plant State"));

}

void UPlantStateNeedManureComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with NeedManure Plant State"));

}

void UPlantStateNeedManureComponent::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with NeedManure Plant State"));

}

void UPlantStateNeedManureComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of NeedManure Plant State Satisfied"));

}

FString UPlantStateNeedManureComponent::NameToString()
{
	return "NeedManure Plant State";
}

