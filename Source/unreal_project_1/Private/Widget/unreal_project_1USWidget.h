// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/EditableText.h>
#include <Components/TextBlock.h>
#include <Components/Button.h>
#include <Components/Slider.h>
#include "unreal_project_1USWidget.generated.h"


/**
 * 
 */
UCLASS()
class Uunreal_project_1USWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	void InitComponents();
	void BindEvents();

	UFUNCTION()//델리게이트 함수앞에는 무조건 이거 넣어줘야함(델리게이트는 기존에 있는 함수를 말함)
	void OnWidthChanged(const FText& Text);

	UFUNCTION()
	void OnHeightChanged(const FText& Text);

	UFUNCTION()
	void OnFullScreenClicked();

	UFUNCTION()
	void OnBorderlessClicked();

	UFUNCTION()
	void OnWindowedClicked();

	UFUNCTION()
	void OnMouseSensitivityChanged(float Value);

	UFUNCTION()
	void OnBrightnessChanged(float Value);

	UFUNCTION()
	void OnExitClicked();

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> EditWidth;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> EditHeight;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonFullScreen;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonBorderless;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonWindowed;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USlider> SliderMouseSensitivity;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextMouseSensitivity;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USlider> SliderBrightness;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextBrightness;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonExit;
};
