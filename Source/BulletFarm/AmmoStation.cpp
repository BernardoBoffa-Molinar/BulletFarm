// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoStation.h"
#include "BulletFarmCharacter.h";
#include <Kismet/GameplayStatics.h>

// Sets default values
AAmmoStation::AAmmoStation()
{
 	

}

void AAmmoStation::OnInteract_Implementation() {
	ABulletFarmCharacter* player = (ABulletFarmCharacter*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (player != nullptr) {
		player->bulletCounts[(int32)ammoType] = player->bulletCapacity;
	}

	// Try and play the sound if specified
	if (fireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, fireSound, this->GetActorLocation());
	}
}

