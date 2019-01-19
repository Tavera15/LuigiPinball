// Fill out your copyright notice in the Description page of Project Settings.

#include "PinballBooster.h"
#include "PinballBall.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"


// Sets default values
APinballBooster::APinballBooster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APinballBooster::BeginPlay()
{
	Super::BeginPlay();
	if (!Pinball) { return; }
	PinballUP = Cast<UPrimitiveComponent>(Pinball->GetRootComponent());
}

// Called every frame
void APinballBooster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APinballBooster::BoostBall() {
	
	if (!PinballUP) { return; }
	UE_LOG(LogTemp, Warning, TEXT("Pinball Found"));
	PinballUP->AddImpulse(FVector(25, 0, 0) * 50, NAME_None, true);
}
