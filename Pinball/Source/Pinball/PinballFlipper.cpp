// Fill out your copyright notice in the Description page of Project Settings.

#include "PinballFlipper.h"
#include "Engine/StaticMesh.h"
#include "EngineUtils.h"
#include "PinballBall.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"



// Sets default values
APinballFlipper::APinballFlipper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APinballFlipper::BeginPlay()
{
	Super::BeginPlay();
	GetComponents(MeshComps);
	MyMesh = MeshComps[0];
	PinballPrimComp = Cast<UPrimitiveComponent>(Pinball->GetRootComponent());
}

// Called every frame
void APinballFlipper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Update the flipper's Flipper Facing property on the editor
void APinballFlipper::PostEditChangeProperty(struct FPropertyChangedEvent& e) {
	Super::PostEditChangeProperty(e);

	FName PropertyName = e.GetPropertyName();
	
	GetComponents(MeshComps);
	MyMesh = MeshComps[0];

	if (PropertyName == GET_MEMBER_NAME_CHECKED(APinballFlipper, FlipperFacing)) {
		if (FlipperFacing == FlipperType::Right) {
			MyMesh->SetRelativeScale3D(FVector(-1, 1, 1));
			
		}
		else {
			MyMesh->SetRelativeScale3D(FVector(1, 1, 1));

		}
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(APinballFlipper, FlipperStatus)) {
		if (FlipperStatus == FlipperRotation::Opened) {
			if (FlipperFacing == FlipperType::Right) {
				MyMesh->SetRelativeRotation(FRotator(0, -30, 0));	// For Right Flipper
			}
			else {
				MyMesh->SetRelativeRotation(FRotator(0, 30, 0));	// For Left Flipper
			}	
		}
		else {
			MyMesh->SetRelativeRotation(FRotator(0, 0, 0));			// Close both Flippers
		}
	}
}
/*
void APinballFlipper::Flip()
{
	if (!MyMesh) {
		UE_LOG(LogTemp, Warning, TEXT("No Mesh in Flip"));
		return;
	}

	if (FlipperFacing == FlipperType::Left)
	{
		MyMesh->SetRelativeRotation(FRotator(0, 30, 0));
	}
	else if (FlipperFacing == FlipperType::Right) {
		MyMesh->SetRelativeRotation(FRotator(0, -30, 0));
	}
	else {
		return;
	}
}

void APinballFlipper::Flop()
{
	if (!MyMesh) {
		UE_LOG(LogTemp, Warning, TEXT("No Mesh in Flip"));
		return;
	}

	if (FlipperFacing == FlipperType::Left)
	{
		MyMesh->SetRelativeRotation(FRotator(0, 0, 0));
		ImpulseBall();
	}
	else if (FlipperFacing == FlipperType::Right) {
		MyMesh->SetRelativeRotation(FRotator(0, 0, 0));
		ImpulseBall();
	}
	else {
		return;
	}
	
}
*/

void APinballFlipper::ImpulseBall() {
	if (!Pinball || !PinballPrimComp) { return; }
	if (IsOverlappingActor(Pinball)) {
		auto FlipperLocation = GetActorLocation();
		auto PinballLocation = Pinball->GetActorLocation();
		auto ImpulseForce = 500;

		auto ImpulseToBall = UKismetMathLibrary::GetDirectionUnitVector(FlipperLocation, PinballLocation);
		ImpulseToBall.Z = 0;

		PinballPrimComp->AddImpulse(ImpulseToBall * ImpulseForce, NAME_None, true);
	}
	//AddImpulseAtLocation(ImpulseToBall, FlipperLocation, NAME_None); //  AddForce(ImpulseToBall * ImpulseForce * PinballPrimComp->GetMass(), NAME_None, true); // 

}
