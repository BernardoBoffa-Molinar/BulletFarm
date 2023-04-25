// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateGrowingComponent.h"

#include "PlantStateMachine.h"

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
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Emerald, TEXT("Entered Growing Plant State"));

}

void UPlantStateGrowingComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Emerald, TEXT("Exited Growing Plant State"));

}

void UPlantStateGrowingComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Emerald, TEXT("Intereacted with Growing Plant State"));
	
	
}

void UPlantStateGrowingComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Emerald, TEXT("Bullet Colision with Growing Plant State"));
	FString Debugmessage;

	switch (BulletType) {
	case Water:
		Debugmessage = "Hit by a Water Bullet";
		break;
		
	case Mud:
		Debugmessage = "Hit by a Mud Bullet";
		break;

	case Seed:
		Debugmessage = "Hit by a Seed Bullet";
		//NeedSatisfied();
		break;
		
	case Pesticide:
		Debugmessage = "Hit bya Pesticide Bullet";
		break;

	case Sun:
		Debugmessage = "Hit by a Sun Bullet";
		break;

	case Manure:
		Debugmessage = "Hit by a Manure Bullet";
		break;
	}
	
}

void UPlantStateGrowingComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Emerald, TEXT("Needs of Growing Plant State Satisfied"));
	PlantStateMachine->SetState(PlantStateMachine->GetCompletePlantState());
}

FString UPlantStateGrowingComponent::NameToString()
{
	return "Growing Plant State";
}

