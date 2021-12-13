// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer == EAutoReceiveInput::Player0;
	bUseControllerRotationYaw = false;

	// Setting up camera

	playerCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));

		// Puts camera at the center of the player, and moves with it
	playerCam->AttachTo(RootComponent);

		// Offsets the camera from the center
	playerCam->SetRelativeLocation(FVector(0, 0, 30));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveVertically"), this, &APlayerCharacter::MoveVertically);
	PlayerInputComponent->BindAxis(TEXT("MoveHorizontally"), this, &APlayerCharacter::MoveHorizontally);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::VRotation);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &APlayerCharacter::Jump);
}

// Player Movement
void APlayerCharacter::MoveVertically(float axisValue)
{
	AddMovementInput(GetActorForwardVector()* axisValue);
}

void APlayerCharacter::MoveHorizontally(float axisValue)
{
	AddMovementInput(GetActorRightVector() * axisValue);
}

// Camera Rotation
void APlayerCharacter::HRotation(float rotVal)
{
	UE_LOG(LogTemp, Warning, TEXT("fre"));

	if (rotVal)
		AddActorLocalRotation(FRotator(0, rotVal, 0));
}

void APlayerCharacter::VRotation(float rotVal)
{
	if (rotVal)
	{
		// Limits the camera's rotation range
		float x = playerCam->GetRelativeRotation().Pitch + rotVal;

		if (x < 65 && x > -65)
		{
			playerCam->AddLocalRotation(FRotator(rotVal, 0, 0));
		}
	}
}