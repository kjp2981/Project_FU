// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "Bed_Drawer.generated.h"

UCLASS()
class ABed_Drawer : public AActor, public IIInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABed_Drawer();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	TObjectPtr<class UStaticMeshComponent> openablePart;

	bool bOpen = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interaction() override;
};
