// Fill out your copyright notice in the Description page of Project Settings.


#include "Classic_Cupboard.h"
#include <Components/StaticMeshComponent.h>

// Sets default values
AClassic_Cupboard::AClassic_Cupboard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClassic_Cupboard::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AClassic_Cupboard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AClassic_Cupboard::Interaction()
{
	bOpened = !bOpened;

	if (IsValid(leftDoorMesh) && IsValid(rightDoorMesh)) {
		if (bOpened) {
			leftDoorMesh->SetRelativeRotation(FRotator(0, 100, 0));
			rightDoorMesh->SetRelativeRotation(FRotator(0, -100, 0));
		}
		else {
			leftDoorMesh->SetRelativeRotation(FRotator(0, 0, 0));
			rightDoorMesh->SetRelativeRotation(FRotator(0, 0, 0));
		}
	}
}

