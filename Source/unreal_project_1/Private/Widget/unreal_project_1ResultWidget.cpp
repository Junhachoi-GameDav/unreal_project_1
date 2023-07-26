// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/unreal_project_1ResultWidget.h"
#include <GamePlay/unreal_project_1GameMode.h>
#include <Kismet/GameplayStatics.h>
#include "Blueprint/WidgetTree.h"
#include "Components/GridSlot.h"

void Uunreal_project_1ResultWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitRankingCPP();
}

void Uunreal_project_1ResultWidget::InitRankingCPP()
{
	Aunreal_project_1GameMode* GameMode = Cast<Aunreal_project_1GameMode>(UGameplayStatics::GetGameMode(this));
	if(GameMode)
	{
		int32 Ranking = GameMode->GetRankingCPP();
		TArray<float> Scores = GameMode->GetRankingScoresCPP();
		TArray<FString> Times = GameMode->GetRankingTimesCPP();
		
		{
			FString Text = TEXT("Your Ranking = #") + FString::FromInt(Ranking);
			TextRanking->SetText(FText::FromString(Text));
		}

		//Num은 크기 또는 갯수
		for (int32 i = 0; i < Scores.Num(); i++)
		{
			int32 Row = i + 1;

			UTextBlock* Rank = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Rank)
			{
				Rank->SetText(FText::AsNumber(Row));
				UGridSlot* ChildSlot =  RankingTable->AddChildToGrid(Rank, Row, 0);
				ChildSlot->SetNudge(FVector2D(0.0, 20.0 * Row)); // ui 위치
			}

			UTextBlock* Score = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Score)
			{
				Score->SetText(FText::AsNumber(Scores[i]));
				UGridSlot* ChildSlot = RankingTable->AddChildToGrid(Score, Row, 1);
				ChildSlot->SetNudge(FVector2D(200.0, 20.0 * Row));
			}

			UTextBlock* Time = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
			if (Time)
			{
				Time->SetText(FText::FromString(Times[i]));
				UGridSlot* ChildSlot = RankingTable->AddChildToGrid(Time, Row, 2);
				ChildSlot->SetNudge(FVector2D(400.0, 20.0 * Row));
			}
		}
	}
}
