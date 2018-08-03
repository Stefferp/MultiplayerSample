// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEMULTIPLAYER_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();
	
protected:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		float MovingSpeed = 25;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector TargetLocation;

	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
};
