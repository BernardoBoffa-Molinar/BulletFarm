// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateBareComponent.h"

#include "PlantStateMachine.h"

// Sets default values for this component's properties
UPlantStateBareComponent::UPlantStateBareComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlantStateBareComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlantStateBareComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UPlantStateBareComponent::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void UPlantStateBareComponent::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Red, TEXT("Entered Bare Plant State"));
}

void UPlantStateBareComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Red, TEXT("Exited Bare Plant State"));

}

void UPlantStateBareComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Red, TEXT("Intereacted with Bare Plant State"));

}

void UPlantStateBareComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Red, TEXT("Bullet Colision with  Bare Plant State"));
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
			NeedSatisfied();
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

void UPlantStateBareComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Red, TEXT("Needs of Bare Plant State Satisfied"));
	PlantStateMachine->SetState(PlantStateMachine->GetGrowingPlantState());
}

FString UPlantStateBareComponent::NameToString()
{
	return "Bare Plant State";
}


