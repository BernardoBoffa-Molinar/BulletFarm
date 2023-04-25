// Copyright Epic Games, Inc. All Rights Reserved.


#include "TP_WeaponComponent.h"
#include "BulletFarmCharacter.h"
#include "BulletFarmProjectile.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values for this component's properties
UTP_WeaponComponent::UTP_WeaponComponent()
{
	// Default offset from the character location for projectiles to spawn
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
}


void UTP_WeaponComponent::Fire()
{
	if (Character == nullptr || Character->GetController() == nullptr)
	{
		return;
	}
	if (Character->bulletCounts[(int32)Character->selectedBullet] <= 0) {
		if (EmptySound != nullptr) {
			UGameplayStatics::PlaySoundAtLocation(this, EmptySound, Character->GetActorLocation());
		}
	
		return;
	}
	
	Character->bulletCounts[(int32)Character->selectedBullet]--;

	// Try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);
	
			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
			// Spawn the projectile at the muzzle
			ABulletFarmProjectile* projectile = World->SpawnActor<ABulletFarmProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			projectile->SetType(Character->selectedBullet);
		}
	}
	
	// Try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, Character->GetActorLocation());
	}
	
	// Try and play a firing animation if specified
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

void UTP_WeaponComponent::SwapAmmoLeft() {
	Character->selectedBullet =  TEnumAsByte<BulletType>((((int32) Character->selectedBullet) + 5) % 6); 
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Emerald, TEXT("Ammo swapped left"));
	DebugAmmoType();
}

void UTP_WeaponComponent::SwapAmmoRight() {
	Character->selectedBullet =  TEnumAsByte<BulletType>((((int32) Character->selectedBullet) + 1) % 6); 
	GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Emerald, TEXT("Ammo swapped right"));
	DebugAmmoType();
}

void UTP_WeaponComponent::DebugAmmoType()
{
	FString Debugmessage = "";
	switch ((int32) Character->selectedBullet) {
	case 0:
		Debugmessage = "I am a Water Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Cyan, Debugmessage  );

		break;
	case 1:
		
		Debugmessage = "I am a Mud Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Turquoise, Debugmessage  );
		break;
	case 2:
	
		Debugmessage = "I am a Seed Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::White, Debugmessage  );
		break;
	case 3:

		Debugmessage = "I am a Pesticide Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Purple, Debugmessage  );
		break;
	case 4:

		Debugmessage = "I am a Sun Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Yellow, Debugmessage  );
		break;
	case 5:
		Debugmessage = "I am a Manure Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Silver, Debugmessage  );
		break;
	}

}

void UTP_WeaponComponent::AttachWeapon(ABulletFarmCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	if (Character == nullptr)
	{
		return;
	}

	// Attach the weapon to the First Person Character
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));
	
	// switch bHasRifle so the animation blueprint can switch to another animation set
	Character->SetHasRifle(true);

	// Set up action bindings
	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Set the priority of the mapping to 1, so that it overrides the Jump action with the Fire action when using touch input
			Subsystem->AddMappingContext(FireMappingContext, 1);
		}

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			// Fire
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UTP_WeaponComponent::Fire);
			EnhancedInputComponent->BindAction(SwapAmmoLeftAction, ETriggerEvent::Triggered, this, &UTP_WeaponComponent::SwapAmmoLeft);
			EnhancedInputComponent->BindAction(SwapAmmoRightAction, ETriggerEvent::Triggered, this, &UTP_WeaponComponent::SwapAmmoRight);
		}
	}
}

void UTP_WeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Character == nullptr)
	{
		return;
	}

	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(FireMappingContext);
		}
	}
}


