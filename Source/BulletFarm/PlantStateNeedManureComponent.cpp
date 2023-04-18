// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateNeedManureComponent.h"

#include "PlantStateMachine.h"

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
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Silver, TEXT("Entered NeedManure Plant State"));

}

void UPlantStateNeedManureComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Silver, TEXT("Exited NeedManure Plant State"));

}

void UPlantStateNeedManureComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Silver, TEXT("Intereacted with NeedManure Plant State"));

}

void UPlantStateNeedManureComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Silver, TEXT("Bullet Colision with NeedManure Plant State"));
	

	if( BulletType == BulletType::Manure)
	{
		NeedSatisfied();
	}
	else
	{
		// inform player the plant need Manure
		//Interact in BP
		PlantStateMachine->DecreasedPlantGrowingScore();
	}
	
}

void UPlantStateNeedManureComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Silver, TEXT("Needs of NeedManure Plant State Satisfied"));
	PlantStateMachine->IncreasedPlantGrowingScore();
	PlantStateMachine->SetState(PlantStateMachine->GetGrowingPlantState());
}

FString UPlantStateNeedManureComponent::NameToString()
{
	return "NeedManure Plant State";
}

