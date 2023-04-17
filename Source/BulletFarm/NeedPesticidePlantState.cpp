// Fill out your copyright notice in the Description page of Project Settings.


#include "NeedPesticidePlantState.h"

// Sets default values
ANeedPesticidePlantState::ANeedPesticidePlantState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeedPesticidePlantState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeedPesticidePlantState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ANeedPesticidePlantState::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void ANeedPesticidePlantState::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered NeedWPesticide Plant State"));

}

void ANeedPesticidePlantState::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited NeedWPesticide Plant State"));

}

void ANeedPesticidePlantState::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with NeedWPesticide Plant State"));

}

void ANeedPesticidePlantState::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with NeedWPesticide Plant State"));

}

void ANeedPesticidePlantState::NeedStatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of NeedWPesticide Plant State Satisfied"));

}

FString ANeedPesticidePlantState::NameToString()
{
	return "NeedWPesticide Plant State";
}


