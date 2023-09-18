// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "IInteractable.h"
#include "DoorWalter_a.generated.h"

/**
 * 
 */
UCLASS()
class ADoorWalter_a : public AStaticMeshActor, public IIInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorWalter_a();

public:
	bool bOpenable = false;
	bool bOpen = false;

	UPROPERTY(EditAnywhere, Category = Door)
	TObjectPtr<UStaticMeshComponent> doorBarricadeMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interaction() override;
};
