// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SupplyChainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SUPPLYCHAIN_API ASupplyChainGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	void ActorDied(AActor* DeadActor);
	

protected:

	virtual void BeginPlay() override;

private:

	class APlayerClass* Player;
};
