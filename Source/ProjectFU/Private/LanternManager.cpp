// Fill out your copyright notice in the Description page of Project Settings.


#include "LanternManager.h"
#include "Lantern_a.h"
#include <Components/StaticMeshComponent.h>
#include <Components/SceneComponent.h>
#include "Engine/StaticMeshActor.h"
#include "Components/PointLightComponent.h"


// Sets default values for this component's properties
ULanternManager::ULanternManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	 
	// ...
}


// Called when the game starts
void ULanternManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (lightArray.Num() == 0) {
		for (int i = 0; i < iLanternCount; i++) {
			//ALantern_a* lantern = CreateDefaultSubobject<ALantern_a>(TEXT("Lantern" + i));
			ALantern_a* lantern = GetWorld()->SpawnActor<ALantern_a>(lanternFactory, FTransform());
			if (lantern != nullptr) {
				lantern->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
				lantern->SetActorRelativeLocation(lanternPosArray[i]->GetRelativeLocation());
				lightArray.Add(lantern);
			}
		}
	}
}


// Called every frame
void ULanternManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULanternManager::SetVisiblaLight(int index, bool value)
{
	if (lightArray.IsValidIndex(index)) {
		if (lightArray[index] != nullptr) {
			lightArray[index]->GetLanternLight()->SetVisibility(value);
		}
	}
}

