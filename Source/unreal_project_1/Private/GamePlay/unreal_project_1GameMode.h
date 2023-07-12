// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "unreal_project_1GameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(Funreal_project_1GameModeOnEndGame, Aunreal_project_1GameMode, OnEndGameCPP);
/**
 *
 */
UCLASS()
class Aunreal_project_1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		void UpdateRankingCPP();

public:

	//델리게이트 = 이벤트 함수(on ~ bind 뭐시기들)
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		Funreal_project_1GameModeOnEndGame OnEndGameCPP;

protected:
	UPROPERTY(Category = GameMode, VisibleAnywhere, BlueprintReadWrite)
		FDateTime StartTimeCPP;

	UPROPERTY(Category = GameMode, VisibleAnywhere, BlueprintReadWrite)
		FDateTime EndTimeCPP;

	//배열
	UPROPERTY(Category = GameMode, VisibleAnywhere, BlueprintReadWrite)
		TArray<float> RankingScoresCPP;

	UPROPERTY(Category = GameMode, VisibleAnywhere, BlueprintReadWrite)
		TArray<FString> RankingTimesCPP;

	UPROPERTY(Category = GameMode, VisibleAnywhere, BlueprintReadWrite)
		int32 RankingCPP;

	UPROPERTY(Category = GameMode, VisibleAnywhere, BlueprintReadWrite)
		float ScoreCPP;
};
