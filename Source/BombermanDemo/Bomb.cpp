// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomb.h"

#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"


// Sets default values
ABomb::ABomb()
{
    PrimaryActorTick.bCanEverTick = true;

    SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
    RootComponent = SphereMesh;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(
        TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere")
    );
    if (SphereMeshAsset.Succeeded())
    {
        SphereMesh->SetStaticMesh(SphereMeshAsset.Object);
    }
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
    Super::BeginPlay();
}

void ABomb::OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
                         AActor* OtherActor,
                         UPrimitiveComponent* OtherComp,
                         int32 OtherBodyIndex)
{
    if (OtherActor != this &&
        OtherComp->GetCollisionObjectType() == AllowedObjectType)
    {
        SphereMesh->SetCollisionProfileName(FName("BlockAll"));
    }
}

void ABomb::SetupPlayerOverlapOnce(const FName& CollisionProfileName,
                                   ECollisionChannel ObjectType)
{
    AllowedObjectType = ObjectType;
    SphereMesh->SetCollisionProfileName(CollisionProfileName);
    SphereMesh->OnComponentEndOverlap.AddDynamic(this, &ABomb::OnOverlapEnd);
}
