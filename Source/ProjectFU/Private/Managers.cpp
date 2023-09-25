// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers.h"
#include <Blueprint/UserWidget.h>
#include <Blueprint/WidgetTree.h>
#include <Widgets/Text/STextBlock.h>

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

void UManagers::AddKey()
{
	keyArray.Add(1);
}