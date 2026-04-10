// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpawner.h"
#include "MyActor_TimedPlatform.h"
#include "MyActor_Rotation.h"
// Sets default values
AMySpawner::AMySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMySpawner::BeginPlay()
{
    Super::BeginPlay();

    for (int32 i = 0; i < SpawnCount; i++)
    {
        FRotator RandomRotation = FRotator(0.f, FMath::RandRange(0.f, 360.f), 0.f);

        // 1. 이동 발판 소환
        if (MovePlatformClass)
        {
            FVector RandomLocation = GetActorLocation() + FVector(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 0.f);
            GetWorld()->SpawnActor<AMyActor_TimedPlatform>(MovePlatformClass, RandomLocation, RandomRotation);
        }

        // 2. 회전 발판 소환 
        if (RotationPlatformClass)
        {
            FVector RandomLocation2 = GetActorLocation() + FVector(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 0.f);
            GetWorld()->SpawnActor<AMyActor_Rotation>(RotationPlatformClass, RandomLocation2, RandomRotation);
        }
    }
}
// Called every frame
void AMySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

