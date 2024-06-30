#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameEndInterface.h"
#include "MyGameState.generated.h"

UCLASS()
class FOR4TALE_API AMyGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    AMyGameState();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Timer")
    int32 TimerValue;

    UFUNCTION(BlueprintCallable, Category = "Timer")
    void StartTimer(int32 Duration);

private:
    FTimerHandle TimerHandle;
    void UpdateTimer();

    void NotifyGameEnd();
};

