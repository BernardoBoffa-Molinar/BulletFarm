// Fill out your copyright notice in the Description page of Project Settings.


#include "CompletePlantState.h"

// Sets default values
ACompletePlantState::ACompletePlantState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACompletePlantState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACompletePlantState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ACompletePlantState::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void ACompletePlantState::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered Complete Plant State"));
}

void ACompletePlantState::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited Complete Plant State"));

}

void ACompletePlantState::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with Complete Plant State"));

}

void ACompletePlantState::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with  Complete Plant State"));

}

void ACompletePlantState::NeedStatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of Complete Plant State Satisfied"));
}

FString ACompletePlantState::NameToString()
{
	return "Complete Plant State";
}

