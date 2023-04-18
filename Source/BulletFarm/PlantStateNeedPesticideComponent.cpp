// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateNeedPesticideComponent.h"

// Sets default values for this component's properties
UPlantStateNeedPesticideComponent::UPlantStateNeedPesticideComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlantStateNeedPesticideComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlantStateNeedPesticideComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlantStateNeedPesticideComponent::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void UPlantStateNeedPesticideComponent::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered NeedWPesticide Plant State"));

}

void UPlantStateNeedPesticideComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited NeedWPesticide Plant State"));

}

void UPlantStateNeedPesticideComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with NeedWPesticide Plant State"));

}

void UPlantStateNeedPesticideComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with NeedWPesticide Plant State"));

}

void UPlantStateNeedPesticideComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of NeedWPesticide Plant State Satisfied"));

}

FString UPlantStateNeedPesticideComponent::NameToString()
{
	return "NeedWPesticide Plant State";
}

