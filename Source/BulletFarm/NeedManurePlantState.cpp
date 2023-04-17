// Fill out your copyright notice in the Description page of Project Settings.


#include "NeedManurePlantState.h"

// Sets default values
ANeedManurePlantState::ANeedManurePlantState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeedManurePlantState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeedManurePlantState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANeedManurePlantState::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void ANeedManurePlantState::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered NeedManure Plant State"));

}

void ANeedManurePlantState::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited NeedManure Plant State"));

}

void ANeedManurePlantState::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with NeedManure Plant State"));

}

void ANeedManurePlantState::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with NeedManure Plant State"));

}

void ANeedManurePlantState::NeedStatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of NeedManure Plant State Satisfied"));

}

FString ANeedManurePlantState::NameToString()
{
	return "NeedManure Plant State";
}
