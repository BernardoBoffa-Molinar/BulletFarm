// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletHitTest.h"

// Sets default values
ABulletHitTest::ABulletHitTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABulletHitTest::OnBulletHit_Implementation(TEnumAsByte<BulletType>& type) {
	UE_LOG(LogTemp, Warning, TEXT("Hit!"));
}

// Called when the game starts or when spawned
void ABulletHitTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletHitTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

