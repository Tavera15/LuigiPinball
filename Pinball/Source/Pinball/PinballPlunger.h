// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinballPlunger.generated.h"

UCLASS()
class PINBALL_API APinballPlunger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinballPlunger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "ChargeEvent")
		void Charge();

	UFUNCTION(BlueprintImplementableEvent, Category = "LaunchEvent")
		void LaunchBall();
	
};
