// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/unreal_project_1PlayerController.h"
#include <EnhancedInputSubsystems.h>
#include "unreal_project_1GameMode.h"
#include <Kismet/GameplayStatics.h>

void Aunreal_project_1PlayerController::OnEndGameCPP()
{
	UUserWidget* Widget = CreateWidget(this, ResultWidget);
	if (Widget) {
		//뷰포트에 띄우기
		Widget->AddToViewport();
	}
}

void Aunreal_project_1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		//인풋 버튼 매핑
		Subsystem->AddMappingContext(unreal_project_1InputMappingContext, 0);
	}

	UUserWidget* Widget = CreateWidget(this, GamePlayWidget);
	if (Widget) {
		//뷰포트에 띄우기
		Widget->AddToViewport();
	}

	//게임모드 가져오기
	Aunreal_project_1GameMode* GameMode = Cast<Aunreal_project_1GameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode) 
	{
		//소스코드에서 델리게이트를 사용하기위한 함수
		GameMode->OnEndGameCPP.AddUniqueDynamic(this, &Aunreal_project_1PlayerController::OnEndGameCPP);
	}
}
