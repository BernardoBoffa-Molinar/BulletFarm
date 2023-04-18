// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateMachine.h"

#include "PlantStateBareComponent.h"
#include "PlantStateCompleteComponent.h"
#include "PlantStateGrowingComponent.h"
#include "PlantStateNeedManureComponent.h"
#include "PlantStateNeedMudComponent.h"
#include "PlantStateNeedPesticideComponent.h"
#include "PlantStateNeedSunComponent.h"
#include "PlantStateNeedWaterComponent.h"


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

  if(CurrentState == GrowingState)
  {
    PlantTimer+= DeltaTime;
    if(PlantTimer>=PlantCooldown)
    {
      CreatePlantNeed();
    }
  }


  
}


void APlantStateMachine::Initialization()
{

  BareComponent = NewObject<UPlantStateBareComponent>(this);
  BareState = Cast<IPlantState>(BareComponent);
  BareState->SetPlantStateMachine(this);
  
  GrowingComponent = NewObject<UPlantStateGrowingComponent>(this);
  GrowingState = Cast<IPlantState>(GrowingComponent);
  GrowingState->SetPlantStateMachine(this);
  
  CompleteComponent = NewObject<UPlantStateCompleteComponent>(this);
  CompleteState = Cast<IPlantState>(CompleteComponent);
  CompleteState->SetPlantStateMachine(this);



  NeedWaterComponent = NewObject<UPlantStateNeedWaterComponent>(this);
  NeedWaterState = Cast<IPlantState>(NeedWaterComponent);
  NeedWaterState->SetPlantStateMachine(this);

  NeedMudComponent = NewObject<UPlantStateNeedMudComponent>(this);
  NeedMudState = Cast<IPlantState>(NeedMudComponent);
  NeedMudState->SetPlantStateMachine(this);

  NeedSunComponent = NewObject<UPlantStateNeedSunComponent>(this);
  NeedSunState = Cast<IPlantState>(NeedSunComponent);
  NeedSunState->SetPlantStateMachine(this);

  NeedManureComponent = NewObject<UPlantStateNeedManureComponent>(this);
  NeedManureState = Cast<IPlantState>(NeedManureComponent);
  NeedManureState->SetPlantStateMachine(this);

  NeedPesticideComponent = NewObject<UPlantStateNeedPesticideComponent>(this);
  NeedPesticideState = Cast<IPlantState>(NeedPesticideComponent);
  NeedPesticideState->SetPlantStateMachine(this);
  
  SetState(BareState);

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

void APlantStateMachine::IncreasedPlantGrowingScore()
{
    PlantScore++;
  if(PlantScore>5)
  {
    PlantScore = 5;
  }
}

void APlantStateMachine::DecreasedPlantGrowingScore()
{
  PlantScore--;
  if(PlantScore<0)
  {
    PlantScore = 0;
  }
}

void APlantStateMachine::CreatePlantNeed()
{
  int index= rand() % 5;
    
  // Assign a random option to the variable based on the random index
  switch (index) {
    case 0:
      //type = BulletType::Water;
      //Debugmessage = "I am a Water Bullet";
      SetState(NeedWaterState);
    break;
    
    case 1:
      //type = BulletType::Mud;
      //Debugmessage = "I am a Mud Bullet";
      SetState(NeedMudState);
    break;
    
    case 2:
      //type = BulletType::Sun;
      //Debugmessage = "I am a Seed Bullet";
      SetState(NeedSunState);
    break;
    
    case 3:
      //type = BulletType::Pesticide;
      //Debugmessage = "I am a Pesticide Bullet";
      SetState(NeedPesticideState);
    break;

    case 4:
      //type = BulletType::Manure;
      //Debugmessage = "I am a Pesticide Bullet";
      SetState(NeedManureState);
    break;
    
  }

  PlantTimer = 0;
  
}


void APlantStateMachine::OnBulletHit(TEnumAsByte<BulletType> typeofBullet)
{
	UE_LOG(LogTemp, Warning, TEXT("Bullet Hit the Plant!"));
  FString Debugmessage ="";
  switch (typeofBullet) {
  case Water:
    Debugmessage = "Hit by a Water Bullet";
    break;
  case Mud:
	
    Debugmessage = "Hit by a Mud Bullet";
    break;
  case Seed:
	
    Debugmessage = "Hit by a Seed Bullet";
    break;
  case Pesticide:
	
    Debugmessage = "Hit bya Pesticide Bullet";
    break;
  case Sun:
    Debugmessage = "Hit by a Sun Bullet";
    break;
  }
  GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Purple, Debugmessage );

 // GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, this->GetCurrentStateName() );

  CurrentState->OnBulletCollision(typeofBullet);
	//IReactToBulletInterface::OnBulletHit(type);
}

