// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinballBall.generated.h"

class APinballBumper;
class APinballKillZone;
class APinballBooster;

UCLASS()
class PINBALL_API APinballBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinballBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ImpulseBall(float DeltaTime);

	UPROPERTY(EditAnywhere)
		FVector DefaultSpeed = FVector(0, -2000, 0);

	UPROPERTY(EditAnywhere)
		float TableStickiness = 5000;

	UPROPERTY(EditAnywhere)
		APinballKillZone* KillZone;

	UPROPERTY(EditAnywhere)
		APinballBooster* Booster;

	TArray<APinballBumper*> ArrayOfBumpers;
	FVector ImpulseToGround;

	
	
private:
	int BumperNumHit;
	int LastBumperHit;
	
	UPrimitiveComponent* BallUPrimitive = nullptr;

	bool IsHittingBumper();

	void GetAllBumpers(TArray<APinballBumper*> &ArrayOfBumpers);

	bool OnKillZone();

	bool OnBooster();


};
