// Fill out your copyright notice in the Description page of Project Settings.


#include "GrowingPlantState.h"

// Sets default values
AGrowingPlantState::AGrowingPlantState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrowingPlantState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrowingPlantState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrowingPlantState::SetPlantStateMachine(APlantStateMachine* Plant)
{
	PlantStateMachine = Plant;
}

void AGrowingPlantState::OnStateEnter()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow, TEXT("Entered Growing Plant State"));

}

void AGrowingPlantState::OnStateExit()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Red, TEXT("Exited Growing Plant State"));

}

void AGrowingPlantState::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green, TEXT("Intereacted with Growing Plant State"));

}

void AGrowingPlantState::OnBulletCollision(float BulletType)
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Black, TEXT("Bullet Colision with Growing Plant State"));

}

void AGrowingPlantState::NeedStatisfied()
{
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, TEXT("Needs of Growing Plant State Satisfied"));

}

FString AGrowingPlantState::NameToString()
{
	return "Growing Plant State";
}

