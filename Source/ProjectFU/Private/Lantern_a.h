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

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Lantern, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class ALanternManager> lanternManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Lantern, meta = (AllowPrivateAccess = "true"))
	int iId;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lantern)
	TObjectPtr<UPointLightComponent> lanternLight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lantern)
	TObjectPtr<class UParticleSystem> candleFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lantern)
	TObjectPtr<class UParticleSystemComponent> candleFireComp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interaction() override;

	TObjectPtr<UPointLightComponent> GetLanternLight() {
		return lanternLight;
	}

	void SetVisible(bool value);

	void SetID(int id);

	int GetID() {
		return this->iId;
	}
};
