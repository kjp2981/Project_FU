// Fill out your copyright notice in the Description page of Project Settings.


#include "Lantern_a.h"

ALantern_a::ALantern_a()
{
	PrimaryActorTick.bCanEverTick = true;
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
