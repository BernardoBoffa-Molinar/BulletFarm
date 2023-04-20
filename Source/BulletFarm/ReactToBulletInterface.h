#pragma once

#include "BulletType.h"
#include "ReactToBulletInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UReactToBulletInterface : public UInterface
{
    GENERATED_BODY()
};

class IReactToBulletInterface
{    
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent)
    void OnBulletHit(TEnumAsByte<BulletType>& type);
};