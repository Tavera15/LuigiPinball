// Fill out your copyright notice in the Description page of Project Settings.

#include "PinballKillZone.h"
#include "PinballBall.h"


// Sets default values
APinballKillZone::APinballKillZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APinballKillZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APinballKillZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APinballKillZone::KillBall() {
	if (!Pinball) { return; }
	Pinball->SetActorLocation(FVector(-1400, 610, -50));
}
