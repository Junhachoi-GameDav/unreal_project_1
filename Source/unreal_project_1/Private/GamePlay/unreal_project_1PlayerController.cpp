// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/unreal_project_1PlayerController.h"
#include <EnhancedInputSubsystems.h>

void Aunreal_project_1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		//맵핑 콘텍스트는 인풋에 키를 넣는다는 의미의 단어= 클라스이름도 저런식으로 되어있다.
		Subsystem->AddMappingContext(unreal_project_1InputMappingContext, 0); //0은 pri 함수안에 옵션뭐시기이다.
	}
}
