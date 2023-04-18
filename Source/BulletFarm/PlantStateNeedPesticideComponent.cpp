// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateNeedPesticideComponent.h"
#include "PlantStateMachine.h"
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
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Purple, TEXT("Entered Need Pesticide Plant State"));

}

void UPlantStateNeedPesticideComponent::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Purple, TEXT("Exited Need Pesticide Plant State"));

}

void UPlantStateNeedPesticideComponent::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Purple, TEXT("Intereacted with Need Pesticide Plant State"));

}

void UPlantStateNeedPesticideComponent::OnBulletCollision(BulletType BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Purple, TEXT("Bullet Colision with Need Pesticide Plant State"));
	if( BulletType == BulletType::Pesticide)
	{
		NeedSatisfied();
	}
	else
	{
		// inform player the plant need Pesticide
		//Interact in BP
		PlantStateMachine->DecreasedPlantGrowingScore();
	}
}

void UPlantStateNeedPesticideComponent::NeedSatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Purple, TEXT("Needs of Need Pesticide Plant State Satisfied"));
	PlantStateMachine->IncreasedPlantGrowingScore();
	PlantStateMachine->SetState(PlantStateMachine->GetGrowingPlantState());

}

FString UPlantStateNeedPesticideComponent::NameToString()
{
	return "NeedWPesticide Plant State";
}

