#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameEndInterface.generated.h"

UINTERFACE(MinimalAPI)
class UGameEndInterface : public UInterface
{
    GENERATED_BODY()
};

class FOR4TALE_API IGameEndInterface
{
    GENERATED_BODY()

public:
    // ќбъ€вл€ем метод окончани€ игры
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Game")
    void OnGameEnd();
};
