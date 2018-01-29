// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BombermanCharacter.generated.h"

UCLASS()
class BOMBERMANDEMO_API ABombermanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABombermanCharacter();
	void ApplyDirectionInputs(const FVector2D DirectionInputs);
	void SpawnBomb();

	UPROPERTY(EditDefaultsOnly, Category=Bomb)
	TSubclassOf<class ABomb> BombType;

	UPROPERTY(EditDefaultsOnly, Category=Bomb)
	FName BombCollisionProfileName;

private:
	FVector CalculateDesiredBombLocation() const;
};
