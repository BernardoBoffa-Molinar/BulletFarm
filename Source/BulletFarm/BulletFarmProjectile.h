// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletType.h"
#include "BulletData.h"
#include "ReactToBulletInterface.h"
#include "BulletFarmProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS(config=Game)
class ABulletFarmProjectile : public AActor, public IReactToBulletInterface
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	ABulletFarmProjectile();

	//UPROPERTY(EditAnywhere, Catergory = Weapon, meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<BulletType> type;

	UPROPERTY(EditAnywhere)
	TArray<FBulletData> bulletDatas;
	
	void SetType(TEnumAsByte<BulletType> newType);
	TEnumAsByte<BulletType> GetType();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
	
};

