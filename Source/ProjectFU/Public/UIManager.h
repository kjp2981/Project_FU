// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFU_API UUIManager : public UObject
{
	GENERATED_BODY()
	
private:
	static UUIManager* instance;

public:
	static UUIManager* getInstance();
};
