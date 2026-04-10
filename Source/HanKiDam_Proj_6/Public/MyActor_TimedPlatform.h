// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include "MyActor_TimedPlatform.generated.h"

UCLASS()
class HANKIDAM_PROJ_6_API AMyActor_TimedPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor_TimedPlatform();

protected:
	// Called when the game starts or when spawned
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TimePlatform|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimePlatform|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimePlatform|Components")
	float MoveSpeed;

	//자신의 위치와 타겟 위치를 담음
	FVector StartLocation;
	FVector MoveLocation;
	//나가야 할 방향
	FVector Direction;

	//시작 <-> 목적지까지의 거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Components")
	float MaxRange;

	// 발판이 사라질 때 사용할 핸들
	FTimerHandle DestroyTimerHandle;

	// 사라지는 기능을 실행할 함수
	void DestroyPlatform();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
