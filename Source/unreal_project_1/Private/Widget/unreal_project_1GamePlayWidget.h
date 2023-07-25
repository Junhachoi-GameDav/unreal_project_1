// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "unreal_project_1GamePlayWidget.generated.h"


/**
 * 
 */
UCLASS()
class Uunreal_project_1GamePlayWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable)
	void TickTimeCPP();

//bindwidget Ű���尡 ������ �����Ϳ��� �̾����� �ʾƵ� �ڵ�� ui�� ����ְų� ���� ����
//�� ������ �̸��� ���ƾ���
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextTime;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextRemainingBullets;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextMaxRemainingBullets;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextWeaponName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextFireMode;
};
