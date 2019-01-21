// Fill out your copyright notice in the Description page of Project Settings.

#include "PinballBumper.h"
#include "PinballBall.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"


// Sets default values
APinballBumper::APinballBumper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
void APinballBumper::BeginPlay()
{
	Super::BeginPlay();

	// Variable responsible to add impulse to the pinball
	PinballPrimComp = Cast<UPrimitiveComponent>(Pinball->GetRootComponent());
	
	

}

// Called every frame
void APinballBumper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APinballBumper::BumpBall() {	
	if (!Pinball || !PinballPrimComp) { return; }

	auto FromBumperLocation = GetActorLocation();
	auto ToBallLocation = Pinball->GetActorLocation();
	
	// Takes two vectors and finds the unit direction vector between the two,
	// and then multiplys result by the impulse force value
	auto ImpulseToBall = UKismetMathLibrary::GetDirectionUnitVector(FromBumperLocation, ToBallLocation) * (ImpulseForce);
	ImpulseToBall.Z = 0;

	PinballPrimComp->AddImpulse(ImpulseToBall, NAME_None, true);
	
}
