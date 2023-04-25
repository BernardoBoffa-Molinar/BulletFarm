// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateCompleteComponent.h"

#include "PlantStateMachine.h"

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
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Black, TEXT("Entered Complete Plant State"));
}

void UPlantStateCompleteComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Black, TEXT("Exited Complete Plant State"));

}

void UPlantStateCompleteComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Black, TEXT("Intereacted with Complete Plant State"));
	NeedSatisfied();
	

}

void UPlantStateCompleteComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Black, TEXT("Bullet Colision with  Complete Plant State"));
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
		break;
	case Pesticide:
		Debugmessage = "Hit bya Pesticide Bullet";
		break;
	case Sun:
		Debugmessage = "Hit by a Sun Bullet";
		break;
	}
}

void UPlantStateCompleteComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Black, TEXT("Needs of Complete Plant State Satisfied"));
	PlantStateMachine->UpdateScore();
	PlantStateMachine->ResetPlantScore();
	PlantStateMachine->SetState(PlantStateMachine->GetBarePlantState());
}

FString UPlantStateCompleteComponent::NameToString()
{
	return "Complete Plant State";
}

