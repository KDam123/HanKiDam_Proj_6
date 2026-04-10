// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor_Rotation.h"

// Sets default values
AMyActor_Rotation::AMyActor_Rotation()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Scrapopolis/Meshes/Props/SM_Debris_gear_3.SM_Debris_gear_3"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	// 틱 함수 켜주기
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 270.0f;
}

// Called when the game starts or when spawned
void AMyActor_Rotation::BeginPlay()
{

	Super::BeginPlay();
	
}


// Called every frame
void AMyActor_Rotation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(!FMath::IsNearlyZero(RotationSpeed))
	{
	// 초당 RotationSpeed만큼, 한 프레임당 (RotationSpeed * DeltaTime)만큼 회전
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

