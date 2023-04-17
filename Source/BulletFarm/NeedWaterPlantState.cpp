// Fill out your copyright notice in the Description page of Project Settings.


#include "NeedWaterPlantState.h"

// Sets default values
ANeedWaterPlantState::ANeedWaterPlantState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeedWaterPlantState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeedWaterPlantState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANeedWaterPlantState::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void ANeedWaterPlantState::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered NeedWater Plant State"));

}

void ANeedWaterPlantState::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited NeedWater Plant State"));

}

void ANeedWaterPlantState::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with NeedWater Plant State"));

}

void ANeedWaterPlantState::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with NeedWater Plant State"));

}

void ANeedWaterPlantState::NeedStatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of NeedWater Plant State Satisfied"));

}

FString ANeedWaterPlantState::NameToString()
{
	return "NeedWater Plant State";
}
