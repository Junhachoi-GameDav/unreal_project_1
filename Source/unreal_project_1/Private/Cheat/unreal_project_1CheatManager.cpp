// Fill out your copyright notice in the Description page of Project Settings.


#include "Cheat/unreal_project_1CheatManager.h"
#include <Settings/unreal_project_1UserSettings.h>

void Uunreal_project_1CheatManager::PSSetResolution(int32 Width, int32 Height)
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetScreenResolution(FIntPoint(Width, Height));
		UserSettings->ApplySettings(false);
	}
}

void Uunreal_project_1CheatManager::PSSetWindowMode(int32 WindowMode)
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		EWindowMode::Type NewWindowMode = (EWindowMode::Type)WindowMode;
		UserSettings->SetFullscreenMode(NewWindowMode);
		UserSettings->ApplySettings(false);
	}
}

void Uunreal_project_1CheatManager::PSSetMouseSensitivity(float Value)
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetMouseSensitivity(Value);
		UserSettings->ApplySettings(false);
	}
}

void Uunreal_project_1CheatManager::PSSetBrightness(float Value)
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetAutoExposureBrightness(Value);
		UserSettings->ApplySettings(false);
	}
}
