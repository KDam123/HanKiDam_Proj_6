// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <vector>
#include "MyActor_Move.generated.h"

UCLASS()
class HANKIDAM_PROJ_6_API AMyActor_Move : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor_Move();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Move|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Components")
	float MoveSpeed;

	//자신의 위치와 타겟 위치를 담음
    FVector StartLocation;
	FVector MoveLocation;
	//나가야 할 방향
	FVector Direction;

	//시작 <-> 목적지까지의 거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move|Components")
	float MaxRange;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
