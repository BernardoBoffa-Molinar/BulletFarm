// Fill out your copyright notice in the Description page of Project Settings.


#include "BarePlantState.h"

// Sets default values
ABarePlantState::ABarePlantState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarePlantState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarePlantState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarePlantState::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void ABarePlantState::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered Bare Plant State"));
}

void ABarePlantState::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited Bare Plant State"));

}

void ABarePlantState::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with Bare Plant State"));

}

void ABarePlantState::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with  Bare Plant State"));

}

void ABarePlantState::NeedStatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of Bare Plant State Satisfied"));
}

FString ABarePlantState::NameToString()
{
	return "Bare Plant State";
}



