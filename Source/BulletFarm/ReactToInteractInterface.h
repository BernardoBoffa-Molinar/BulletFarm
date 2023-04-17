#pragma once

#include "BulletType.h"
#include "ReactToInteractInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UReactToInteractInterface : public UInterface
{
    GENERATED_BODY()
};

class IReactToInteractInterface
{    
    GENERATED_BODY()

public:
    virtual void OnInteract();
};