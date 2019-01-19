// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinballBooster.generated.h"

class APinballBall;

UCLASS()
class PINBALL_API APinballBooster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinballBooster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void BoostBall();

	UPROPERTY(EditAnywhere)
		APinballBall* Pinball;

	UPrimitiveComponent* PinballUP = nullptr;
	
};
