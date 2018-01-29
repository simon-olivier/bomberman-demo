// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBERMANDEMO_API ABomb : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABomb();

    void SetupPlayerOverlapOnce(const FName& CollisionProfileName,
                                ECollisionChannel ObjectType);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Bomb,
              meta=(AllowPrivateAccess="true"))
    class UStaticMeshComponent* SphereMesh;

    ECollisionChannel AllowedObjectType;
};
