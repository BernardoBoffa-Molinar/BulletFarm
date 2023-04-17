// Fill out your copyright notice in the Description page of Project Settings.


#include "NeedSunPlantState.h"

// Sets default values
ANeedSunPlantState::ANeedSunPlantState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeedSunPlantState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeedSunPlantState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANeedSunPlantState::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void ANeedSunPlantState::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered NeedSun Plant State"));

}

void ANeedSunPlantState::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited NeedSun Plant State"));

}

void ANeedSunPlantState::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with NeedSun Plant State"));

}

void ANeedSunPlantState::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with NeedSun Plant State"));

}

void ANeedSunPlantState::NeedStatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of NeedSun Plant State Satisfied"));

}

FString ANeedSunPlantState::NameToString()
{
	return "NeedSun Plant State";
}


