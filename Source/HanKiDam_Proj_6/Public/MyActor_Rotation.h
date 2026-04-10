// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor_Rotation.generated.h"

UCLASS()
class HANKIDAM_PROJ_6_API AMyActor_Rotation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor_Rotation();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rotation|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rotation|Components")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
