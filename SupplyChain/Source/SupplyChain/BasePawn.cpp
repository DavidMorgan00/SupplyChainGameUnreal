// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.h"


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



void ABasePawn::RotateEnemy(FVector LookAtTarget)
{
	FVector toTarget = LookAtTarget - characterMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, toTarget.Rotation().Yaw, 0.f);
	characterMesh->SetWorldRotation(LookAtRotation);
}

void ABasePawn::Fire()
{
	FVector ProjectileSpawnPointLocation = ProjectileSpawnPoint->GetComponentLocation();

	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();

	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	Projectile->SetOwner(this);
}

