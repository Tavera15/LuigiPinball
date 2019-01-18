// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinballFlipper.generated.h"

class APinballBall;

UENUM(BlueprintType)
enum class FlipperType : uint8 {
	Left,
	Right
};

UENUM()
enum class FlipperRotation : uint8 {
	Closed,
	Opened
};


UCLASS()
class PINBALL_API APinballFlipper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APinballFlipper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
		FlipperType FlipperFacing;

	UPROPERTY(EditAnywhere)
		FlipperRotation FlipperStatus = FlipperRotation::Opened;

	UPROPERTY(EditAnywhere)
	APinballBall* Pinball = nullptr;

	void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

	UStaticMeshComponent* MyMesh = nullptr;
	UPrimitiveComponent* PinballPrimComp = nullptr;

	TArray<UStaticMeshComponent*>MeshComps;

	UFUNCTION(BlueprintImplementableEvent, Category = "FlipEvent")
		void Flip();

	UFUNCTION(BlueprintImplementableEvent, Category = "FlopEvent")
		void Flop();
	
	void ImpulseBall();

private:
	
};
