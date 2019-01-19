// Fill out your copyright notice in the Description page of Project Settings.

#include "PinballBall.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "PinballBumper.h"
#include "PinballKillZone.h"
#include "PinballBooster.h"
#include "EngineUtils.h"

// Sets default values
APinballBall::APinballBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APinballBall::BeginPlay()
{
	Super::BeginPlay();
	BallUPrimitive = Cast<UPrimitiveComponent>(GetRootComponent());

	GetAllBumpers(ArrayOfBumpers);		// Initialize the TArray of bumpers

}

// Called every frame
void APinballBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ImpulseBall(DeltaTime);

	// Only impulse the pinball if it hits a bumper
	if (IsHittingBumper()) {
		ArrayOfBumpers[BumperNumHit]->BumpBall();
	}

	if (OnKillZone()) {
		KillZone->KillBall();
	}

	if (OnBooster()) {
		Booster->BoostBall();
	}
	
}


// Add impulse force on the pinball to stay in ground and move across
void APinballBall::ImpulseBall(float DeltaTime) {

	if (!BallUPrimitive) { return; }

	auto TravelSpeed = DefaultSpeed * DeltaTime;

	// This impulse is responsible for traveling across the Y-axis
	BallUPrimitive->AddImpulse(TravelSpeed, NAME_None, true);

	// Get Hit Result Z units below ball, and return true if it detects anything
	FHitResult OUTHitResult;
	bool GetBallLineTrace = GetWorld()->LineTraceSingleByChannel(
		OUTHitResult,
		GetActorLocation(),
		GetActorLocation() - FVector(0, 0, 500),
		ECollisionChannel::ECC_Visibility);

	// If boolean above returns true, add an impulse to force the ball downwards towards Hit Result
	if (GetBallLineTrace) {
		ImpulseToGround = ((OUTHitResult.ImpactNormal * -1.0) * (DeltaTime * TableStickiness));
		BallUPrimitive->AddImpulse(ImpulseToGround, NAME_None, true);
	}

}

// Returns true if the pinball is hitting a bumper
bool APinballBall::IsHittingBumper() {
	
	for (int i = 0; i < ArrayOfBumpers.Num(); i++)
	{
		if (IsOverlappingActor(ArrayOfBumpers[i])) {
			BumperNumHit = i;
			return true;
		}
	}
	return false;
}

// Is responsible for searching all bumpers and storing them in a TArray
void APinballBall::GetAllBumpers(TArray<APinballBumper*> &ArrayOfBumpers) {
	for (TActorIterator<APinballBumper> Bumpers(GetWorld()); Bumpers; ++Bumpers) {
		ArrayOfBumpers.Add(*Bumpers);
	}
}

bool APinballBall::OnKillZone() {
	if (IsOverlappingActor(KillZone)) {
		return true;
	}
	return false;
}

bool APinballBall::OnBooster() {
	if (IsOverlappingActor(Booster)) {
		return true;
	}
	return false;
}