// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanPlayerController.h"

#include "BombermanCharacter.h"

ABombermanPlayerController::ABombermanPlayerController(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	bAutoManageActiveCameraTarget = false;
}

void ABombermanPlayerController::Tick(float DeltaTime)
{
	ABombermanCharacter* Character = Cast<ABombermanCharacter>(GetPawn());
	if (Character)
	{
		if (!DirectionInputs.IsZero())
		{
			Character->ApplyDirectionInputs(DirectionInputs);
		}
	}
}

void ABombermanPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, 
		&ABombermanPlayerController::ListenMoveForward);
	InputComponent->BindAxis("MoveRight", this,
		&ABombermanPlayerController::ListenMoveRight);
}

void ABombermanPlayerController::ListenMoveForward(float AxisInput)
{
	DirectionInputs.X = FMath::Clamp(AxisInput, -1.0f, 1.0f);
}

void ABombermanPlayerController::ListenMoveRight(float AxisInput)
{
	DirectionInputs.Y = FMath::Clamp(AxisInput, -1.0f, 1.0f);
}

