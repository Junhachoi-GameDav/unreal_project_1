// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "unreal_project_1SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class Uunreal_project_1SaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<float> ScoreCPP;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FString> TimesCPP;
};
