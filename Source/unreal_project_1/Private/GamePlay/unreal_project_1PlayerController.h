// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <Widget/unreal_project_1GamePlayWidget.h>
#include <InputMappingContext.h>
#include "unreal_project_1PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class Aunreal_project_1PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void OnEndGameCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputMappingContext> unreal_project_1InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> GamePlayWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> ResultWidget;
};
