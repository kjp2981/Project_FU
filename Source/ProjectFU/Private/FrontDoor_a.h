// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "IInteractable.h"
#include "FrontDoor_a.generated.h"

/**
 * 
 */
UCLASS()
class AFrontDoor_a : public AStaticMeshActor, public IIInteractable
{
	GENERATED_BODY()
	
public:
	AFrontDoor_a();

private:
	bool bOpenable = false;
	bool bOpen = false;

	UPROPERTY(EditAnywhere, Category = Door, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> doorBarricadeMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interaction() override;

	void OpenDoor(bool value);
};
