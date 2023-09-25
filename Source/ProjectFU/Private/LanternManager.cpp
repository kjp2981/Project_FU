// Fill out your copyright notice in the Description page of Project Settings.


#include "LanternManager.h"
#include "Lantern_a.h"


// Sets default values
ALanternManager::ALanternManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALanternManager::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<TObjectPtr<USceneComponent>> ChildArray;
	ChildArray = RootComponent->GetAttachChildren();

	if (ChildArray.Num() != 0) {
		for (int i = 0; i < ChildArray.Num(); i++) {
			TObjectPtr<ALantern_a> lantern = Cast<ALantern_a>(ChildArray[i]->GetOwner());
			if (lantern != nullptr) {
				lantern->SetID(i);
				lanternArray.Add(lantern);
			}
		}
	}
}

// Called every frame
void ALanternManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALanternManager::SetLanternVisible(int id, bool value)
{
	if (id < lanternArray.Num()) {
		for (int i = 0; i < lanternArray.Num(); i++) {
			if (lanternArray[i]->GetID() == id) {
				lanternArray[i]->GetLanternLight()->SetVisibility(value);
				break;
			}
		}
	}
}

void ALanternManager::SetLanternAutoVisible(int id)
{
	if (id < lanternArray.Num()) {
		for (int i = 0; i < lanternArray.Num(); i++) {
			if (lanternArray[i]->GetID() == id) {
				lanternArray[i]->GetLanternLight()->SetVisibility(!lanternArray[i]->GetLanternLight()->IsVisible());
				break;
			}
		}
	}
}

void ALanternManager::SetOtherLanternAutoVisible(int id)
{
	TArray<int> OtherIdArray;
	for (auto pair : idPairStruct) {
		if (pair.ownerId == id) {
			OtherIdArray = pair.otherIdArray;
			break;
		}
	}

	for (int i = 0; i < OtherIdArray.Num(); i++) {
		for (int j = 0; j < lanternArray.Num(); j++) {
			if (lanternArray[j]->GetID() == OtherIdArray[i]) {
				lanternArray[j]->GetLanternLight()->SetVisibility(!lanternArray[j]->GetLanternLight()->IsVisible());
			}
		}
	}
}
  