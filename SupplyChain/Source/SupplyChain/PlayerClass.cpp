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

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerClass::Move);
}

void APlayerClass::Move(float value)
{
	FVector deltaLocation(0.0f, 0.0f, 0.0f);
	float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	deltaLocation.X = value * deltaTime * speed;
	AddActorLocalOffset(deltaLocation);
}
