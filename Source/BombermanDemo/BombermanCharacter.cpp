// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

#include "Bomb.h"


// Sets default values
ABombermanCharacter::ABombermanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void ABombermanCharacter::ApplyDirectionInputs(const FVector2D DirectionInputs)
{
	AddMovementInput(FVector(1.0f, .0f, .0f), DirectionInputs.X);
	AddMovementInput(FVector(.0f, 1.0f, .0f), DirectionInputs.Y);
}

void ABombermanCharacter::SpawnBomb()
{
    FActorSpawnParameters ActorSpawnParameters;
    ActorSpawnParameters.SpawnCollisionHandlingOverride =
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    FVector DesiredLocation = GetActorLocation();
    DesiredLocation.Z = 40;

    ABomb* SpawnedBomb = GetWorld()->SpawnActor<ABomb>(
        BombType,
        CalculateDesiredBombLocation(),
        FRotator::ZeroRotator,
        ActorSpawnParameters
    );
    SpawnedBomb->SetupPlayerOverlapOnce(
        BombCollisionProfileName,
        GetCapsuleComponent()->GetCollisionObjectType()
    );
}

FVector ABombermanCharacter::CalculateDesiredBombLocation() const
{
    return FVector(
        FMath::RoundHalfToZero(GetActorLocation().X / 100) * 100,
        FMath::RoundHalfToZero(GetActorLocation().Y / 100) * 100,
        40
    );
}
