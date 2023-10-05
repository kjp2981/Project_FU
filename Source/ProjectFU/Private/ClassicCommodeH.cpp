// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassicCommodeH.h"

// Sets default values
AClassicCommodeH::AClassicCommodeH()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClassicCommodeH::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClassicCommodeH::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AClassicCommodeH::Interaction()
{
	bOpen = !bOpen;

	if (bOpen) {
		for (auto& drawr : drawerArray) {
			drawr->AddRelativeLocation(FVector(0, 33, 0));
		}
	}
	else {
		for (auto& drawr : drawerArray) {
			drawr->AddRelativeLocation(FVector(0, -33, 0));
		}
	}
}

