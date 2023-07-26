#include "GamePlay/unreal_project_1GameMode.h"

void Aunreal_project_1GameMode::UpdateRankingCPP()
{
	int32 RankingIndex = 0;
	//Num()은 크기이다. 또는 갯수
	for (int32 i = 0; i < RankingScoresCPP.Num(); i++)
	{
		float element = RankingScoresCPP[i];
		if (element >= ScoreCPP)
		{
			RankingIndex++;
		}
		else
		{
			break;
		}
	}

	RankingCPP = RankingIndex + 1;
	RankingScoresCPP.Insert(ScoreCPP, RankingIndex);
	RankingTimesCPP.Insert(EndTimeCPP.ToString(), RankingIndex);
	if (RankingScoresCPP.Num() > 10)
	{
		RankingScoresCPP.RemoveAt(RankingScoresCPP.Num() - 1);
		RankingTimesCPP.RemoveAt(RankingTimesCPP.Num() - 1);
	}
}

StateOfGameCPP Aunreal_project_1GameMode::GetStateCPP() const
{
	return StateCPP;
}

FDateTime Aunreal_project_1GameMode::GetStartTimeCPP() const
{
	return StartTimeCPP;
}

int32 Aunreal_project_1GameMode::GetRankingCPP() const
{
	return RankingCPP;
}

TArray<float> Aunreal_project_1GameMode::GetRankingScoresCPP() const
{
	return RankingScoresCPP;
}

TArray<FString> Aunreal_project_1GameMode::GetRankingTimesCPP() const
{
	return RankingTimesCPP;
}
