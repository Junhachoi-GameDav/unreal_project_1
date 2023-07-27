// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/unreal_project_1UserSettings.h"

float Uunreal_project_1UserSettings::GetMouseSensitivity() const
{
	return MouseSensitivity;
}

void Uunreal_project_1UserSettings::SetMouseSensitivity(float Value)
{
	MouseSensitivity = Value;
}

float Uunreal_project_1UserSettings::GetAutoExposureBrightness() const
{
	return AutoExposureBrightness;
}

void Uunreal_project_1UserSettings::SetAutoExposureBrightness(float Value)
{
	AutoExposureBrightness = Value;
}

void Uunreal_project_1UserSettings::SetToDefaults()
{
	Super::SetToDefaults();

	MouseSensitivity = 1.0;
	AutoExposureBrightness = 0.0;
}
