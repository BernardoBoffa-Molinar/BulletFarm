// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoStation.h"

// Sets default values
AAmmoStation::AAmmoStation()
{
 	

}

void AAmmoStation::OnInteract() {
	if (gameMode != nullptr) gameMode->RefillAmmo(ammoType);
}

// Called when the game starts or when spawned
void AAmmoStation::BeginPlay()
{
	Super::BeginPlay();
	gameMode = (ABulletFarmGameMode*) GetWorld()->GetAuthGameMode();
}

