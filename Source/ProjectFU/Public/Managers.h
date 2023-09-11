// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Managers.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFU_API UManagers : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUserWidget> mainUIClass;
	class UUserWidget* mainUIWidget;
public:

	virtual void Init() override;
	virtual void Shutdown() override;

	void AddMainUI();
};
