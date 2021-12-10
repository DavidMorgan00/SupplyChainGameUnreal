// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawnbyiu.h"

// Sets default values
AMyPawnbyiu::AMyPawnbyiu()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawnbyiu::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawnbyiu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawnbyiu::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

