// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BulletData.generated.h"

USTRUCT()
struct FBulletData
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	UMaterial* bulletMat;

	UPROPERTY(EditAnywhere)
	UParticleSystem* bulletParticles;
};
