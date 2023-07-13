// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/unreal_project_1PlayerController.h"
#include <EnhancedInputSubsystems.h>
#include "unreal_project_1GameMode.h"
#include <Kismet/GameplayStatics.h>

void Aunreal_project_1PlayerController::OnEndGameCPP()
{
	UUserWidget* Widget = CreateWidget(this, ResultWidget);
	if (Widget) {
		//����Ʈ�� ����
		Widget->AddToViewport();
	}
}

void Aunreal_project_1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		//��ǲ ��ư ����
		Subsystem->AddMappingContext(unreal_project_1InputMappingContext, 0);
	}

	UUserWidget* Widget = CreateWidget(this, GamePlayWidget);
	if (Widget) {
		//����Ʈ�� ����
		Widget->AddToViewport();
	}

	//���Ӹ�� ��������
	Aunreal_project_1GameMode* GameMode = Cast<Aunreal_project_1GameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode) 
	{
		//�ҽ��ڵ忡�� ��������Ʈ�� ����ϱ����� �Լ�
		GameMode->OnEndGameCPP.AddUniqueDynamic(this, &Aunreal_project_1PlayerController::OnEndGameCPP);
	}
}
