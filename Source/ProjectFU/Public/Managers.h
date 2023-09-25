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
#pragma region UI
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUserWidget> mainUIClass;
	class UUserWidget* mainUIWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	TObjectPtr<class UTextBlock> eText;
#pragma endregion
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Key, meta = (AllowPrivateAccess = "true"))
	TArray<bool> keyArray;
public:

	virtual void Init() override;
	virtual void Shutdown() override;

	void AddMainUI();

	int GetKeyNum() {
		return keyArray.Num();
	}

	void AddKey();
};
