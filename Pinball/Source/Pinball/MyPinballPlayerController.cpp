// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPinballPlayerController.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "PinballFlipper.h"


void AMyPinballPlayerController::BeginPlay() {
	Super::BeginPlay();

	ArrangeAllFlippers();
}

// Loop through the array of AllFlippers and bind action using input component
void AMyPinballPlayerController::ArrangeAllFlippers() {
	TArray<AActor*> AllFlippers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),APinballFlipper::StaticClass(), AllFlippers);
	
	InputComponent = FindComponentByClass<UInputComponent>();
	
	if (!InputComponent) {
		UE_LOG(LogTemp, Error, TEXT("No Input Component Found"));
		return;
	}

	if (AllFlippers.Num() > 0) {
		
		for (int i = 0; i < AllFlippers.Num(); i++)
		{
			auto CurrentFlipper = AllFlippers[i];
			auto FlipperPB = Cast<APinballFlipper>(CurrentFlipper);
			
			switch (FlipperPB->FlipperFacing)
			{

			case FlipperType::Left:
				InputComponent->BindAction("LeftFlipper", IE_Pressed, FlipperPB, &APinballFlipper::Flop);
				InputComponent->BindAction("LeftFlipper", IE_Released, FlipperPB, &APinballFlipper::Flip);
				LeftFlippers.Add(FlipperPB);
				break;

			case FlipperType::Right:
				InputComponent->BindAction("RightFlipper", IE_Pressed, FlipperPB, &APinballFlipper::Flop);
				InputComponent->BindAction("RightFlipper", IE_Released, FlipperPB, &APinballFlipper::Flip);
				RightFlippers.Add(FlipperPB);
				break;

			default:
				break;
			}
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No FLippers Found"));
	}
	
}
