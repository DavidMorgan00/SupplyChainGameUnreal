// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "PlayerClass.generated.h"

/**
 * 
 */
UCLASS()
class SUPPLYCHAIN_API APlayerClass : public ABasePawn
{
	GENERATED_BODY()

public:
	APlayerClass();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float speed = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float turnRate = 15.0f;

	void Move(float value);

	void Turn(float value);

	APlayerController* PlayerControllerRef;

};
