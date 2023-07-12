// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/unreal_project_1PlayerController.h"
#include <EnhancedInputSubsystems.h>

void Aunreal_project_1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		//���� ���ؽ�Ʈ�� ��ǲ�� Ű�� �ִ´ٴ� �ǹ��� �ܾ�= Ŭ���̸��� ���������� �Ǿ��ִ�.
		Subsystem->AddMappingContext(unreal_project_1InputMappingContext, 0); //0�� pri �Լ��ȿ� �ɼǹ��ñ��̴�.
	}
}
