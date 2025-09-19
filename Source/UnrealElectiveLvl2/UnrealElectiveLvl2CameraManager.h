// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "UnrealElectiveLvl2CameraManager.generated.h"

/**
 *  Basic First Person camera manager.
 *  Limits min/max look pitch.
 */
UCLASS()
class AUnrealElectiveLvl2CameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:

	/** Constructor */
	AUnrealElectiveLvl2CameraManager();
};
