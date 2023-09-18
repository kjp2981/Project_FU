// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Lantern_a.h"
#include "LanternManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ULanternManager : public USceneComponent
{
	 GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULanternManager();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lantern)
	TSubclassOf<class ALantern_a> lanternFactory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lantern)
	TArray<TObjectPtr<USceneComponent>> lanternPosArray;

	UPROPERTY(VisibleAnywhere, Category = Lantern)
	TArray<TObjectPtr<ALantern_a>> lightArray;

	UPROPERTY(EditAnywhere, Category = Lantern)
	int iLanternCount = 5;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetVisiblaLight(int index, bool value);
};
