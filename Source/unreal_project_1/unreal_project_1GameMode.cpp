// Copyright Epic Games, Inc. All Rights Reserved.

#include "unreal_project_1GameMode.h"
#include "unreal_project_1Character.h"
#include "UObject/ConstructorHelpers.h"

Aunreal_project_1GameMode::Aunreal_project_1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
