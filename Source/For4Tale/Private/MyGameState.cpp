#include "MyGameState.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"
#include "GameFramework/PlayerState.h" 
#include "GameFramework/Controller.h"  
#include "UObject/ConstructorHelpers.h"

AMyGameState::AMyGameState()
{
    TimerValue = 30;
}

void AMyGameState::BeginPlay()
{
    Super::BeginPlay();
}

void AMyGameState::StartTimer(int32 Duration)
{
    TimerValue = Duration;
    GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyGameState::UpdateTimer, 1.0f, true);
}

void AMyGameState::UpdateTimer()
{
    if (TimerValue > 0)
    {
        TimerValue--;
        if (TimerValue == 0)
        {
            GetWorldTimerManager().ClearTimer(TimerHandle);

            NotifyGameEnd();
        }
    }
}

void AMyGameState::NotifyGameEnd()
{
    for (APlayerState* PlayerState : PlayerArray)
    {
        if (AController* Controller = PlayerState->GetOwner<AController>())
        {
            if (Controller->Implements<UGameEndInterface>())
            {
                IGameEndInterface::Execute_OnGameEnd(Controller);
            } 
        }   
    }
}

void AMyGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AMyGameState, TimerValue);
}
