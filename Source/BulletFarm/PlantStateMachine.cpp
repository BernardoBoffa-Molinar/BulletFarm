// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateMachine.h"

#include "PlantStateBareComponent.h"
#include "PlantStateCompleteComponent.h"
#include "PlantStateGrowingComponent.h"


// Sets default values
APlantStateMachine::APlantStateMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlantStateMachine::BeginPlay()
{
	Super::BeginPlay();
	Initialization();
}

// Called every frame
void APlantStateMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlantStateMachine::Initialization()
{

  BareComponent = NewObject<UPlantStateBareComponent>(this);
  BareState = Cast<IPlantState>(BareComponent);
  CompleteComponent = NewObject<UPlantStateCompleteComponent>(this);
  CompleteState = Cast<IPlantState>(CompleteComponent);

  GrowingComponent = NewObject<UPlantStateGrowingComponent>(this);
  GrowingState = Cast<IPlantState>(GrowingComponent);


  
  //BareStateComponet = NewObject<UCPP_BareStateComponet>(this);
  //BareState = Cast<IPlantState>(BareStateComponet);
  //BareState = CreateDefaultSubobject<UCPP_BareStateComponet>(TEXT("BareStateComponent"));
  //BareStateActor = NewObject<UChildActorComponent>(this);
  //BareStateActor->bEditableWhenInherited = true;
  //BareStateActor->RegisterComponent();
  //BareStateActor->SetChildActorClass(ABarePlantState::StaticClass());

  //BareState = Cast<ABarePlantState>(BareStateActor);
 
  //BareState = GetWorld()->SpawnActor<ABarePlantState>(ABarePlantState::StaticClass());
  //Cast<AActor>(BareState)->SetActorLocation(GetActorLocation());
  //Cast<AActor>(BareState)->Rename(TEXT("Bare StateActor"), this, REN_None);
  //Cast<AActor>(BareState)->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

  //Cast<AActor>(BareState)->Rename(TEXT("BareState"), this, REN_None);
  //Cast<AActor>(this)->Children.Add(Cast<AActor>(BareState));
  //Cast<AActor>(BareState)->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
 
   //BareState->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
  SetState(BareState);
  SetState(GrowingState);
  SetState(CompleteState);
}

void APlantStateMachine::SetState(IPlantState* stateToSet)
{
  if(CurrentState!= nullptr)
  {
    CurrentState->OnStateExit();
  }
  CurrentState = stateToSet;
  
  CurrentState->OnStateEnter();
}

FString APlantStateMachine::GetCurrentStateName()
{
  return "Current Plant State: " + CurrentState->NameToString();
}

IPlantState* APlantStateMachine::GetCurrentState()
{
  return CurrentState;
}

IPlantState* APlantStateMachine::GetBarePlantState()
{
  return BareState;
}

IPlantState* APlantStateMachine::GetGrowingPlantState()
{
  return GrowingState;
}

IPlantState* APlantStateMachine::GetCompletePlantState()
{
  return CompleteState;
}

IPlantState* APlantStateMachine::GetNeedMudPlantState()
{
  return NeedMudState;
}

IPlantState* APlantStateMachine::GetNeedWaterPlantState()
{
  return NeedWaterState;
}

IPlantState* APlantStateMachine::GetNeedManurePlantState()
{
  return NeedManureState;
}

IPlantState* APlantStateMachine::GetNeedSunPlantState()
{
  return NeedSunState;
}

IPlantState* APlantStateMachine::GetNeedPesticidePlantState()
{
  return NeedPesticideState;
}



void APlantStateMachine::OnBulletHit(TEnumAsByte<BulletType> type)
{
	UE_LOG(LogTemp, Warning, TEXT("Bullet Hit the Plant!"));
  

  GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, this->GetCurrentStateName() );

  
	//IReactToBulletInterface::OnBulletHit(type);
}

