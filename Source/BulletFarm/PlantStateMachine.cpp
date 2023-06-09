// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateMachine.h"

#include "BulletFarmCharacter.h"
#include <Kismet/GameplayStatics.h>
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
    if(PlantTimer>=PlantCooldown )
    {
      if(PlantScore<5)
      {
        CreatePlantNeed();
      } else
      {
        CurrentState->NeedSatisfied();
      }
    
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
  PlantScore =0;

}

void APlantStateMachine::SetState(IPlantState* stateToSet)
{
  if(CurrentState!= nullptr)
  {
    CurrentState->OnStateExit();
  }
  CurrentState = stateToSet;
  OnChangeShapeEvent.Broadcast();
  CurrentStateName = GetCurrentStateName();
  CurrentState->OnStateEnter();
}

FString APlantStateMachine::GetCurrentStateName()
{
  return "Current: " + CurrentState->NameToString();
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
  OnChangeShapeEvent.Broadcast();
  if(PlantScore>5)
  {
    SetState(CompleteState);
  }
}

void APlantStateMachine::DecreasedPlantGrowingScore()
{
  OnChangeShapeEvent.Broadcast();

  
  PlantScore--;
  if(PlantScore<0)
  {
    //Small Commit test
    PlantScore = 0; 
  }
  
}

void APlantStateMachine::CreatePlantNeed()
{
  int index= rand() % 5;
    
  // Assign a random option to the variable based on the random index
  switch (index) {
    case 0:
      SetState(NeedWaterState);
    break;
    
    case 1:
      SetState(NeedMudState);
    break;
    
    case 2:
      SetState(NeedSunState);
    break;
    
    case 3:
      SetState(NeedPesticideState);
    break;

    case 4:
      SetState(NeedManureState);
    break;
    
  }

  PlantTimer = 0;
  
}

void APlantStateMachine::UpdateScore()
{
  GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Black, "ScoreUpdate" );
  ABulletFarmCharacter* player = (ABulletFarmCharacter*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
  if(player != nullptr)
  {
    player->PlayerScore+=100;
    player->CallToUpdateUI();
  }
}

void APlantStateMachine::ResetPlantScore()
{
  PlantScore = 0;
  OnChangeShapeEvent.Broadcast();
}

FString APlantStateMachine::GetInteractableTextByState()
{
  if(CurrentState != nullptr){

    if(CurrentState == BareState && BareState!=nullptr)
    {
      return  "No Seed In Plant";
    }

    if(CurrentState == GrowingState && GrowingState!=nullptr)
    {
      return  "Plant Is Growing";
    }
      
    if(CurrentState == CompleteState && CompleteState!=nullptr)
    {
      return  "Plant Is Done Growing";
    }

    if(CurrentState == NeedManureState && NeedManureState!=nullptr)
    {
      return  "Plant Needs Manure";
    }
      
    if(CurrentState == NeedWaterState && NeedWaterState!=nullptr)
    {
      return  "Plant Needs Water";
    }

    if(CurrentState == NeedMudComponent && NeedMudComponent!=nullptr)
    {
      return  "Plant Needs Mud";
    }

    if(CurrentState == NeedSunState && NeedSunState!=nullptr)
    {
      return  "Plant Needs Sun";
    }
    
    if(CurrentState == NeedPesticideState && NeedPesticideState!=nullptr)
    {
      return  "Plant Needs Pesticide";
    }
      
  } 
  

  return  " Null Pointer";
  
}


void APlantStateMachine::OnBulletHit_Implementation(TEnumAsByte<BulletType>& typeofBullet)
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
	
    Debugmessage = "Hit by a Pesticide Bullet";
    break;
  case Sun:
    Debugmessage = "Hit by a Sun Bullet";
    break;
  case Manure:
    Debugmessage = "Hit by a Manure Bullet";
    break;
  }
  GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Green, Debugmessage );

 // GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Purple, this->GetCurrentStateName() );

  CurrentState->OnBulletCollision(typeofBullet);
	//IReactToBulletInterface::OnBulletHit(type);
}

void APlantStateMachine::OnInteract_Implementation()
{
  IReactToInteractInterface::OnInteract_Implementation();
  GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Emerald, TEXT("Plant RayCast Hit"));
  
  CurrentState->OnInteract();
  OnPlantInteractEvent.Broadcast();
}


