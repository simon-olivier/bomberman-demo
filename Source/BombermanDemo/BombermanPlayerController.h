// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BombermanPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANDEMO_API ABombermanPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ABombermanPlayerController(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetupInputComponent() override;
	void ListenMoveForward(float AxisInput);
	void ListenMoveRight(float AxisInput);
	void ListenDisposeBomb();

private:
	FVector2D DirectionInputs;
	bool bDisposeBombPressed;
	
};
