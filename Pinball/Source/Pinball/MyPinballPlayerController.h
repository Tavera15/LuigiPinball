// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPinballPlayerController.generated.h"

/**
 * 
 */

class APinballFlipper;

UCLASS()
class PINBALL_API AMyPinballPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;


	UInputComponent* InputComponent = nullptr;

	TArray<APinballFlipper*> LeftFlippers;
	TArray<APinballFlipper*> RightFlippers;

	void ArrangeAllFlippers();

	void SetupPlungerInput();

};
