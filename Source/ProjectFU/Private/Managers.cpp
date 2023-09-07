// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers.h"

void UManagers::Init()
{
	Super::Init();

	static ConstructorHelpers::FClassFinder<UMainUI> mainUI(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/FUContent/Widget/BP_MainUI.BP_MainUI_C'"));
	if (mainUI.Succeeded()) {
		mainUIClass = mainUI.Class;
	}
}

void UManagers::Shutdown()
{
	Super::Shutdown();
}

void UManagers::AddMainUI()
{
	mainUIWidget = CreateWidget<UMainUI>(GetWorld(), mainUIClass);

	if (IsValid(mainUIWidget)) {
		mainUIWidget->AddToViewport();
	}
}
