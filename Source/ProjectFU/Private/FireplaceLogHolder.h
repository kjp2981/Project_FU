// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "IInteractable.h"
#include "FireplaceLogHolder.generated.h"

/**
 * 
 */
UCLASS()
class AFireplaceLogHolder : public AStaticMeshActor, public IIInteractable
{
	GENERATED_BODY()

public:
	AFireplaceLogHolder();
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void Interaction() override;
};
