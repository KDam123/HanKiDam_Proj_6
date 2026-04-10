// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySpawner.generated.h"

UCLASS()
class HANKIDAM_PROJ_6_API AMySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySpawner();

protected:
	// 스폰할 클래스 정보를 담을 변수 (에디터에서 선택 가능하게)
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AMyActor_TimedPlatform> MovePlatformClass; // 이동하다가 5초 뒤에 사라지는 액터

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AMyActor_Rotation> RotationPlatformClass; // 회전하는 액터

	// 몇 개나 스폰할 건지
	int32 SpawnCount = 5;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
