// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers.h"
#include <Blueprint/UserWidget.h>

void UManagers::Init()
{
	Super::Init();

	mainUIWidget = CreateWidget<UUserWidget>(GetWorld(), mainUIClass);

	AddMainUI();
}

void UManagers::Shutdown()
{
	Super::Shutdown();
}

void UManagers::AddMainUI()
{
	if (IsValid(mainUIWidget)) {
		mainUIWidget->AddToViewport();
	}
}
