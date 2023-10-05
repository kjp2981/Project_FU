// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "ClassicCommodeH.generated.h"

UCLASS()
class AClassicCommodeH : public AActor, public IIInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClassicCommodeH();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	TArray<TObjectPtr<UStaticMeshComponent>> drawerArray;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	bool bOpen = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interaction() override;
};
