// Fill out your copyright notice in the Description page of Project Settings.


#include "NeedMudPlantState.h"

// Sets default values
ANeedMudPlantState::ANeedMudPlantState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeedMudPlantState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeedMudPlantState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANeedMudPlantState::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void ANeedMudPlantState::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered NeedMud Plant State"));
}

void ANeedMudPlantState::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited NeedMud Plant State"));

}

void ANeedMudPlantState::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with NeedMud Plant State"));

}

void ANeedMudPlantState::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with  NeedMud Plant State"));

}

void ANeedMudPlantState::NeedStatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of NeedMud Plant State Satisfied"));
}

FString ANeedMudPlantState::NameToString()
{
	return "NeedMud Plant State";
}
