// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateNeedMudComponent.h"
#include "PlantStateMachine.h"
// Sets default values for this component's properties
UPlantStateNeedMudComponent::UPlantStateNeedMudComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlantStateNeedMudComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlantStateNeedMudComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UPlantStateNeedMudComponent::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void UPlantStateNeedMudComponent::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Turquoise, TEXT("Entered NeedMud Plant State"));
}

void UPlantStateNeedMudComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Turquoise, TEXT("Exited NeedMud Plant State"));

}

void UPlantStateNeedMudComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Turquoise, TEXT("Intereacted with NeedMud Plant State"));

}

void UPlantStateNeedMudComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Turquoise, TEXT("Bullet Colision with  NeedMud Plant State"));
	if( BulletType == BulletType::Mud)
	{
		NeedSatisfied();
	}
	else
	{
		// inform player the plant need Mud
		//Interact in BP
		PlantStateMachine->DecreasedPlantGrowingScore();
	}
}

void UPlantStateNeedMudComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Turquoise, TEXT("Needs of NeedMud Plant State Satisfied"));
	PlantStateMachine->IncreasedPlantGrowingScore();
	PlantStateMachine->SetState(PlantStateMachine->GetGrowingPlantState());
}

FString UPlantStateNeedMudComponent::NameToString()
{
	return "NeedMud Plant State";
}


