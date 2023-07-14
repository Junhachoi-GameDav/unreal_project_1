// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "unreal_project_1GamePlayWidget.generated.h"


/**
 * 
 */
UCLASS()
class Uunreal_project_1GamePlayWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	TObjectPtr<UTextBlock> TextTime;

	TObjectPtr<UTextBlock> TextRemainingBullets;

	TObjectPtr<UTextBlock> TextMaxRemainingBullets;

	TObjectPtr<UTextBlock> TextWeaponName;

	TObjectPtr<UTextBlock> TextFireMode;
};
