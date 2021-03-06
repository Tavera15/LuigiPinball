// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinballKillZone.generated.h"

class APinballBall;

UCLASS()
class PINBALL_API APinballKillZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinballKillZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		APinballBall* Pinball;

	UPROPERTY(EditAnywhere)
		bool DoRemoveStock = false;

	void KillBall();
	
	UPrimitiveComponent* PinBallUP = nullptr;
};
