// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = capsuleComponent;

	characterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh"));
	characterMesh->SetupAttachment(capsuleComponent);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawn Point"));
	ProjectileSpawnPoint->SetupAttachment(characterMesh);

}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasePawn::RotateEnemy(FVector LookAtTarget)
{
	FVector toTarget = LookAtTarget - characterMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, toTarget.Rotation().Yaw, 0.f);
	characterMesh->SetWorldRotation(LookAtRotation);
}

