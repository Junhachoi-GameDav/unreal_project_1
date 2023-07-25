// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/unreal_project_1GamePlayWidget.h"
#include <GamePlay/unreal_project_1GameMode.h>
#include <Kismet/GameplayStatics.h>

void Uunreal_project_1GamePlayWidget::TickTimeCPP()
{
	//게임모드 가져오기
	Aunreal_project_1GameMode* GameMode = Cast<Aunreal_project_1GameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode)
	{
		StateOfGameCPP State = GameMode->GetStateCPP();
		FDateTime StartTime = GameMode->GetStartTimeCPP();
		FDateTime Now = FDateTime::Now(); //현재시간
		FTimespan Delta = Now - StartTime;

		switch (State)
		{
		case StateOfGameCPP::Ready:
			TextTime->SetText(FText::FromString(TEXT("")));
			break;

		case StateOfGameCPP::Playing:
			FString Minutes = FString::FromInt(Delta.GetMinutes());
			FString Seconds = FString::FromInt(Delta.GetSeconds());
			FString Milliseconds = FString::FromInt(Delta.GetFractionMilli());
			FString Text = TEXT("Stopwatch > ") + Minutes + TEXT(":") + Seconds + TEXT(".") + Milliseconds;
			TextTime->SetText(FText::FromString(Text));
			break;
		}
	}
}
