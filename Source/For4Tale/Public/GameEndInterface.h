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
    // ��������� ����� ��������� ����
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Game")
    void OnGameEnd();
};
