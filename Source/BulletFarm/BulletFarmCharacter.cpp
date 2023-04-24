// Copyright Epic Games, Inc. All Rights Reserved.

#include "BulletFarmCharacter.h"
#include "BulletFarmProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ReactToInteractInterface.h"
#include "GameFramework/CharacterMovementComponent.h"


//////////////////////////////////////////////////////////////////////////
// ABulletFarmCharacter

ABulletFarmCharacter::ABulletFarmCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	bulletCounts.Init(bulletCapacity, 6);

	//CharacterMovementComponent = Cast<ACharacter>(this)->GetCharacterMovement();
}

void ABulletFarmCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

}

//////////////////////////////////////////////////////////////////////////// Input

void ABulletFarmCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABulletFarmCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABulletFarmCharacter::Look);

		//Looking
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ABulletFarmCharacter::Interact);

		//Sprinting
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &ABulletFarmCharacter::BeginSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ABulletFarmCharacter::EndSprint);
		
	}
}


void ABulletFarmCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//Cast<ACharacter>(this)->GetCharacterMovement()
		
		//CharacterMovementComponent->MaxWalkSpeed
		
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ABulletFarmCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABulletFarmCharacter::Interact() {
	//GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Emerald, TEXT("Try Raycast"));
	FHitResult RV_Hit(ForceInit);
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	if (DoTrace(&RV_Hit, &RV_TraceParams)) {
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Emerald, TEXT("Raycast Hit"));
		IReactToInteractInterface* reactingObject = Cast<IReactToInteractInterface>(RV_Hit.GetActor());
		if (reactingObject != nullptr) {
			reactingObject->Execute_OnInteract(RV_Hit.GetActor());
		}
	}
}

void ABulletFarmCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool ABulletFarmCharacter::GetHasRifle()
{
	return bHasRifle;
}

bool ABulletFarmCharacter::DoTrace(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams)
{
	if (Controller == NULL) // access the controller, make sure we have one
	{
		return false;
	}

	// get the camera transform
	FVector CameraLoc;
	FRotator CameraRot;
	GetActorEyesViewPoint(CameraLoc, CameraRot);

	FVector Start = CameraLoc;
    // you need to add a uproperty to the header file for a float PlayerInteractionDistance
	FVector End = CameraLoc + (CameraRot.Vector() * 200);

	RV_TraceParams->bTraceComplex = true;
	//RV_TraceParams->bTraceAsyncScene = true;
	RV_TraceParams->bReturnPhysicalMaterial = true;

	//  do the line trace
	bool DidTrace = GetWorld()->LineTraceSingleByChannel(
		*RV_Hit,		//result
		Start,		//start
		End,		//end
		ECC_Visibility,	//collision channel
		*RV_TraceParams
		);

	return DidTrace;
}

void ABulletFarmCharacter::BeginSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
	
}

void ABulletFarmCharacter::EndSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}
