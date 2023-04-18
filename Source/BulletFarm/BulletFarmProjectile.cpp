// Copyright Epic Games, Inc. All Rights Reserved.

#include "BulletFarmProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "ReactToBulletInterface.h"

void ABulletFarmProjectile::BeginPlay()
{
	Super::BeginPlay();

	/* Remove when Bullet switching is implemented*/
	int index= rand() % 6;
	FString Debugmessage = "";
	
	switch (index) {
	case 0:
		type = BulletType::Water;
		Debugmessage = "I am a Water Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Cyan, Debugmessage  );

		break;
	case 1:
		type = BulletType::Mud;
		Debugmessage = "I am a Mud Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Turquoise, Debugmessage  );
		break;
	case 2:
		type = BulletType::Seed;
		Debugmessage = "I am a Seed Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::White, Debugmessage  );
		break;
	case 3:
		type = BulletType::Pesticide;
		Debugmessage = "I am a Pesticide Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Purple, Debugmessage  );
		break;
	case 4:
		type = BulletType::Sun;
		Debugmessage = "I am a Sun Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Yellow, Debugmessage  );
		break;
	case 5:
		type = BulletType::Manure;
		Debugmessage = "I am a Manure Bullet";
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Silver, Debugmessage  );
		break;
	}

	
	/* End of Remove*/
}

ABulletFarmProjectile::ABulletFarmProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ABulletFarmProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;


	

	

	

	

	
}

void ABulletFarmProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this))
	{
		IReactToBulletInterface* reactingObject = Cast<IReactToBulletInterface>(OtherActor);
		if (reactingObject != nullptr) {
			reactingObject->OnBulletHit(type);
		}

		Destroy();
	}
	// Only add impulse and destroy projectile if we hit a physics
	//if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	//{
	//	OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
	//
	//	Destroy();
	//}
}
