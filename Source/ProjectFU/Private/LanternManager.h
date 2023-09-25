// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LanternManager.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FIdPair {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	int ownerId;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	TArray<int> otherIdArray;
};

UCLASS()
class ALanternManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALanternManager();

private:
	bool bComplete = false;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Lantern)
	TArray<TObjectPtr<class ALantern_a>> lanternArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Lantern)
	TArray<FIdPair> idPairStruct;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Key)
	TSubclassOf<class ADoorKey> keyFactory;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetLanternVisible(int id, bool value);

	void SetLanternAutoVisible(int id);

	void SetOtherLanternAutoVisible(int id);

	bool GetAllLanternLightVisible(bool isVisible);

	bool GetComplete() {
		return bComplete;
	}
};
