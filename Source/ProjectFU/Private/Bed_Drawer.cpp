// Fill out your copyright notice in the Description page of Project Settings.


#include "Bed_Drawer.h"

// Sets default values
ABed_Drawer::ABed_Drawer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABed_Drawer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABed_Drawer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABed_Drawer::Interaction()
{
	bOpen = !bOpen;

	if (bOpen) {
		openablePart->AddRelativeLocation(FVector(0, 35, 0));
	}
	else {
		openablePart->AddRelativeLocation(FVector(0, -35, 0));
	}
}

