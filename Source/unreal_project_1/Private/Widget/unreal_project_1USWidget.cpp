// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/unreal_project_1USWidget.h"
#include <Settings/unreal_project_1UserSettings.h>

void Uunreal_project_1USWidget::NativeConstruct()
{
	Super::NativeConstruct();
	InitComponents();
	BindEvents();
}

void Uunreal_project_1USWidget::InitComponents()
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		FIntPoint Resoultion = UserSettings->GetScreenResolution();
		EditWidth->SetText(FText::AsNumber(Resoultion.X));
		EditHeight->SetText(FText::AsNumber(Resoultion.Y));

		EWindowMode::Type WindowMode = UserSettings->GetFullscreenMode();
		switch (WindowMode)
		{
		case EWindowMode::Fullscreen:
			ButtonFullScreen->SetIsEnabled(false); //�̹� Ǯ��ũ���̶� �޽��� ó���� üũ
			break;

		case EWindowMode::WindowedFullscreen:
			ButtonBorderless->SetIsEnabled(false);
			break;

		case EWindowMode::Windowed:
			ButtonWindowed->SetIsEnabled(false);
			break;
		}

		float MouseSensitivity = UserSettings->GetMouseSensitivity();
		SliderMouseSensitivity->SetValue(MouseSensitivity);
		TextMouseSensitivity->SetText(FText::AsNumber(MouseSensitivity));

		float AutoExposureBrightness = UserSettings->GetAutoExposureBrightness();
		float Brightness = (AutoExposureBrightness * -1.0) + 5.0; //�ݴ�� -1�� ����
		SliderBrightness->SetValue(Brightness);
		TextBrightness->SetText(FText::AsNumber(Brightness));
	}
}

void Uunreal_project_1USWidget::BindEvents()
{
	EditWidth->OnTextChanged.AddUniqueDynamic(this, &Uunreal_project_1USWidget::OnWidthChanged);
	EditHeight->OnTextChanged.AddUniqueDynamic(this, &Uunreal_project_1USWidget::OnHeightChanged);
	ButtonFullScreen->OnClicked.AddUniqueDynamic(this, &Uunreal_project_1USWidget::OnFullScreenClicked);
	ButtonBorderless->OnClicked.AddUniqueDynamic(this, &Uunreal_project_1USWidget::OnBorderlessClicked);
	ButtonWindowed->OnClicked.AddUniqueDynamic(this, &Uunreal_project_1USWidget::OnWindowedClicked);
	SliderMouseSensitivity->OnValueChanged.AddUniqueDynamic(this, &Uunreal_project_1USWidget::OnMouseSensitivityChanged);
	SliderBrightness->OnValueChanged.AddUniqueDynamic(this, &Uunreal_project_1USWidget::OnBrightnessChanged);
	ButtonExit->OnClicked.AddUniqueDynamic(this, &Uunreal_project_1USWidget::OnExitClicked);
}

//���ڸ� �Է��ؼ� �ػ󵵸� �����ϰ� ���� �Ǿ��ִ�.(���ǰ� �׷�)
void Uunreal_project_1USWidget::OnWidthChanged(const FText& Text)
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		if (Text.IsNumeric())// ���� ���� ���ڰ� �³� �˻�
		{
			FString String = Text.ToString();
			FIntPoint Resolution = UserSettings->GetScreenResolution();
			int32 Width = FCString::Atoi(*String); //string���� ���ڷ� � ������ �˾Ƴ��� �Լ�
			int32 Height = Resolution.Y; //������ �״��

			if (Width >= 720 && Height >= 480)
			{
				UserSettings->SetScreenResolution(FIntPoint(Width, Height));
				UserSettings->ApplySettings(false);
			}
		}
	}
}

void Uunreal_project_1USWidget::OnHeightChanged(const FText& Text)
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		if (Text.IsNumeric())
		{
			FString String = Text.ToString();
			FIntPoint Resolution = UserSettings->GetScreenResolution();
			int32 Width = Resolution.X;
			int32 Height = FCString::Atoi(*String);

			if (Width >= 720 && Height >= 480)
			{
				UserSettings->SetScreenResolution(FIntPoint(Width, Height));
				UserSettings->ApplySettings(false);
			}
		}
	}
}

void Uunreal_project_1USWidget::OnFullScreenClicked()
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		UserSettings->ApplySettings(false);

		//��ư Ȱ��ȭ
		ButtonFullScreen->SetIsEnabled(false);
		ButtonBorderless->SetIsEnabled(true);
		ButtonWindowed->SetIsEnabled(true);
	}
}

void Uunreal_project_1USWidget::OnBorderlessClicked()
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
		UserSettings->ApplySettings(false);

		//��ư Ȱ��ȭ
		ButtonFullScreen->SetIsEnabled(true);
		ButtonBorderless->SetIsEnabled(false);
		ButtonWindowed->SetIsEnabled(true);
	}
}

void Uunreal_project_1USWidget::OnWindowedClicked()
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetFullscreenMode(EWindowMode::Windowed);
		UserSettings->ApplySettings(false);

		//��ư Ȱ��ȭ
		ButtonFullScreen->SetIsEnabled(true);
		ButtonBorderless->SetIsEnabled(true);
		ButtonWindowed->SetIsEnabled(false);
	}
}

void Uunreal_project_1USWidget::OnMouseSensitivityChanged(float Value)
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		UserSettings->SetMouseSensitivity(Value);
		UserSettings->ApplySettings(false);

		TextMouseSensitivity->SetText(FText::AsNumber(Value));
	}
}

void Uunreal_project_1USWidget::OnBrightnessChanged(float Value)
{
	Uunreal_project_1UserSettings* UserSettings = Cast<Uunreal_project_1UserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		float AutoExposureBrightness = (Value -5.0) * -1.0;

		UserSettings->SetAutoExposureBrightness(AutoExposureBrightness);
		UserSettings->ApplySettings(false);

		TextBrightness->SetText(FText::AsNumber(Value));
	}
}

void Uunreal_project_1USWidget::OnExitClicked()
{
	RemoveFromParent(); //�ݱ�
}
