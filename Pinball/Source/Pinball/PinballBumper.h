// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinballBumper.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBumperEvent);

class APinballBall;

UCLASS()
class PINBALL_API APinballBumper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinballBumper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:	
	
	UPrimitiveComponent* PinballPrimComp;
	
	void BumpBall();
	
	
	UPROPERTY(EditAnywhere)
		APinballBall* Pinball = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ImpulseForce = 200;

	UPROPERTY(BlueprintAssignable, Category = "BumperEvent")
		FBumperEvent BumperHitEvent;

	UMaterialInstanceDynamic* matinst = nullptr;
	
};
