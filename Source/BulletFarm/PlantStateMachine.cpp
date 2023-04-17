// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateMachine.h"

#include "BarePlantState.h"

// Sets default values
APlantStateMachine::APlantStateMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlantStateMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlantStateMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlantStateMachine::Initialize()
{
//	BareState = GetWorld()->SpawnActor<ABarePlantState>(ABarePlantState::StaticClass());
	
	
}

