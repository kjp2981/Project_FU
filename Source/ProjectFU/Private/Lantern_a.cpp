// Fill out your copyright notice in the Description page of Project Settings.


#include "Lantern_a.h"

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
	
}

void ALantern_a::Tick(float DeltaTime)
{
}

void ALantern_a::Interaction()
{
	UE_LOG(LogTemp, Log, TEXT("Lantern"));
	if (lanternLight != nullptr) {
		if (lanternLight->IsVisible()) {
			lanternLight->SetVisibility(false);
		}
		else {
			lanternLight->SetVisibility(true);
		}
	}
}