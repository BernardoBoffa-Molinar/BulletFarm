// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BulletType.h"
#include "BulletFarmCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpDateUIEvent);

UCLASS(config=Game)
class ABulletFarmCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* SprintAction;
	
public:
	ABulletFarmCharacter();


    UFUNCTION(BlueprintCallable)
	virtual void SetUpUI(ABulletFarmCharacter* character);
protected:
	virtual void BeginPlay();

public:
    UPROPERTY(VisibleAnywhere)
	TEnumAsByte<BulletType> selectedBullet;
	 UPROPERTY(VisibleAnywhere)
	TArray<int32> bulletCounts;

	UFUNCTION(BlueprintCallable)
	int GetBulletTypeAsInt();

	UFUNCTION(BlueprintCallable)
	int GetBulletCountOfRequestedBullet(int RequestedBullet);
	
	UPROPERTY(EditAnywhere)
	int32 bulletCapacity;
public:
	UPROPERTY(BlueprintAssignable)
	FUpDateUIEvent UIUpdateEvent;

	UFUNCTION()
	void CallToUpdateUI();
	
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;

	/** Bool for AnimBP to switch to another animation set */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	bool bHasRifle;

	/** Setter to set the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void SetHasRifle(bool bNewHasRifle);

	/** Getter for the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	bool GetHasRifle();

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for interact input */
	void Interact();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	bool DoTrace(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams);

	void BeginSprint();

	void EndSprint();
	

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;



	// plant score of growing
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category ="Score")
	int PlayerScore =0;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category ="Score")
	float GameTimer =  300.0f;
	
};

