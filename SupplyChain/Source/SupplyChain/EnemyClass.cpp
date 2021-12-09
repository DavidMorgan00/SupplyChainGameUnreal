// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyClass.h"
#include "PlayerClass.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

void AEnemyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Player != NULL)
	{
		float Distance = FVector::Dist(GetActorLocation(), Player->GetActorLocation());
		
		if (Distance <= AttackRange)
		{
			RotateEnemy(Player->GetActorLocation());
		}
	}
}

void AEnemyClass::BeginPlay()
{
	Super::BeginPlay();



	// Have to cast because we cannot assign a base pawn to Player because Player inherits from BasePawn
	Player = Cast<APlayerClass>(UGameplayStatics::GetPlayerPawn(this, 0));
}