// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerClass.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

APlayerClass::APlayerClass()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void APlayerClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Run the Move method when the axis mappings for "MoveForward" are pressed
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerClass::Move);
	// Run the Turn method when the axis mappings for "Turn" are pressed
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerClass::Turn);
}

void APlayerClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerControllerRef)
	{
		FHitResult hitResult;
		PlayerControllerRef->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false,
			hitResult);

		RotateEnemy(hitResult.ImpactPoint);
	}
}

void APlayerClass::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = Cast<APlayerController>(GetController());
}

void APlayerClass::Move(float value)
{
	FVector deltaLocation(0.0f, 0.0f, 0.0f);
	float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	deltaLocation.X = value * deltaTime * speed;
	AddActorLocalOffset(deltaLocation);
}

void APlayerClass::Turn(float value)
{
	FRotator deltaRotation = FRotator::ZeroRotator;
	// Calculates the delta time
	float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	// Yaw = value * deltaTime * turnRate
	deltaRotation.Yaw = value * turnRate * deltaTime;
	AddActorLocalRotation(deltaRotation, true);
}
