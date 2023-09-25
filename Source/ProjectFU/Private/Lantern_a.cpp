// Fill out your copyright notice in the Description page of Project Settings.


#include "Lantern_a.h"
#include "LanternManager.h"

ALantern_a::ALantern_a()
{
	PrimaryActorTick.bCanEverTick = true;

	lanternLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("LanternLight"));
	if (lanternLight != nullptr) {
		lanternLight->SetupAttachment(RootComponent);
		lanternLight->Intensity = 3000;
		lanternLight->AttenuationRadius = 300;
	}
}

void ALantern_a::BeginPlay()
{
	TObjectPtr<AActor> Parent = GetAttachParentActor();
	if (Parent != nullptr) {
		lanternManager = Cast<ALanternManager>(Parent);
	}

	if (lanternLight) {
		lanternLight->SetVisibility(false);
	}
}

void ALantern_a::Tick(float DeltaTime)
{
}

void ALantern_a::Interaction()
{
	// 자신의 랜턴을 칸다음 자신의 id를 lanternmanager에 넘겨
	// lanternmanager는 id를 받은 다음 해당 id의 맞는 다른 id의 랜턴을 켜

	if (lanternLight != nullptr) {
		if (lanternLight->IsVisible()) {
			lanternLight->SetVisibility(false);
			
		}
		else {
			lanternLight->SetVisibility(true);
		}
	}

	if (lanternManager != nullptr) {
		lanternManager->SetOtherLanternAutoVisible(GetID());
	}
}

void ALantern_a::SetID(int id)
{
	this->iId = id; 
}