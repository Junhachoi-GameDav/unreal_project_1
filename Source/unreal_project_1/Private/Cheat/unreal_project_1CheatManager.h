// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "unreal_project_1CheatManager.generated.h"

/**
 * 
 */
UCLASS()
class Uunreal_project_1CheatManager : public UCheatManager
{
	GENERATED_BODY()
	
public:
	UFUNCTION(exec)
	void PSSetResolution(int32 Width, int32 Height);
	
	UFUNCTION(Exec)
	void PSSetWindowMode(int32 WindowMode);
	
	UFUNCTION(Exec)
	void PSSetMouseSensitivity(float Value);

	UFUNCTION(Exec)
	void PSSetBrightness(float Value);
};
