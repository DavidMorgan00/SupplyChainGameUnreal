// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnemyClass.generated.h"

/**
 * 
 */
UCLASS()
class SUPPLYCHAIN_API AEnemyClass : public ABasePawn
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;

	void HandleDeath();
	
protected:

	virtual void BeginPlay() override;


private:

	class APlayerClass* Player;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
		float AttackRange = 100.f;

	FTimerHandle FireRateTimerhandle;
	float FireRate = 2.f;

	void CheckFireCondition();

	bool InFireRange();
		
};
