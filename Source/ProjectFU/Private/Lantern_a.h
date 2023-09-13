// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "IInteractable.h"
#include <Components/PointLightComponent.h>
#include "Lantern_a.generated.h"

/**
 * 
 */
UCLASS()
class ALantern_a : public AStaticMeshActor, public IIInteractable
{
	GENERATED_BODY()
	
public:
	ALantern_a();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Light)
	TObjectPtr<class UPointLightComponent> lanternLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interaction() override;
};
