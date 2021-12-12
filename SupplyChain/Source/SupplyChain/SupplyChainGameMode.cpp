// Fill out your copyright notice in the Description page of Project Settings.


#include "SupplyChainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerClass.h"
#include "EnemyClass.h"

void ASupplyChainGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Player)
	{
		Player->HandleDeath();
		if (Player->GetPlayerController())
		{
			Player->DisableInput(Player->GetPlayerController());
			Player->GetPlayerController()->bShowMouseCursor = false;

		}
	}

	else if (AEnemyClass* DeadEnemy = Cast<AEnemyClass>(DeadActor))
	{
		DeadEnemy->HandleDeath();
	}
}

void ASupplyChainGameMode::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<APlayerClass>(UGameplayStatics::GetPlayerPawn(this, 0));
}