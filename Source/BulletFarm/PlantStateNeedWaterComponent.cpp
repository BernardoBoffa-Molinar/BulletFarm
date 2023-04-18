// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateNeedWaterComponent.h"
#include "PlantStateMachine.h"
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
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Cyan, TEXT("Entered NeedWater Plant State"));

}

void UPlantStateNeedWaterComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Cyan, TEXT("Exited NeedWater Plant State"));

}

void UPlantStateNeedWaterComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Cyan, TEXT("Intereacted with NeedWater Plant State"));

}

void UPlantStateNeedWaterComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Cyan, TEXT("Bullet Colision with NeedWater Plant State"));
	if( BulletType == BulletType::Water)
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

void UPlantStateNeedWaterComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Cyan, TEXT("Needs of NeedWater Plant State Satisfied"));
	PlantStateMachine->IncreasedPlantGrowingScore();
	PlantStateMachine->SetState(PlantStateMachine->GetGrowingPlantState());
}

FString UPlantStateNeedWaterComponent::NameToString()
{
	return "NeedWater Plant State";
}
