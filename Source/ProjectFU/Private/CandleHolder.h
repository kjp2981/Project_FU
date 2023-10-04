// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "CandleHolder.generated.h"

UCLASS()
class ACandleHolder : public AActor, public IIInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACandleHolder();

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	TObjectPtr<class UStaticMeshComponent> staticMeshComp;

	UPROPERTY(VisibleAnywhere, Category = Particle)
	TObjectPtr<class UParticleSystem> fireParticle;

	UPROPERTY(VisibleAnywhere, Category = Particle)
	TObjectPtr<class UParticleSystemComponent> fireParticleComp;

	UPROPERTY(VisibleAnywhere, Category = Light)
	TObjectPtr<class UPointLightComponent> lightComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Light)
	bool bTurnOn = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interaction() override;
};
