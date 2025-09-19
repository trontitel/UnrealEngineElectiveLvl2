// Copyright Epic Games, Inc. All Rights Reserved.


#include "UnrealElectiveLvl2PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "UnrealElectiveLvl2CameraManager.h"
#include "Blueprint/UserWidget.h"
#include "UnrealElectiveLvl2.h"
#include "Widgets/Input/SVirtualJoystick.h"

AUnrealElectiveLvl2PlayerController::AUnrealElectiveLvl2PlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AUnrealElectiveLvl2CameraManager::StaticClass();
}

void AUnrealElectiveLvl2PlayerController::BeginPlay()
{
	Super::BeginPlay();

	
	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogUnrealElectiveLvl2, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void AUnrealElectiveLvl2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
	
}
