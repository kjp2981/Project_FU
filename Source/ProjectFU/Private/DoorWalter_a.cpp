// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorWalter_a.h"
#include "Managers.h"
#include <Kismet/GameplayStatics.h>
#include <Components/StaticMeshComponent.h>

ADoorWalter_a::ADoorWalter_a()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarricadeMesh(TEXT("/Script/Engine.StaticMesh'/Game/EF_FirstFloor/Meshes/DoorBarricade_a.DoorBarricade_a'"));
	if (BarricadeMesh.Succeeded()) {
		doorBarricadeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Barricade"));
		doorBarricadeMesh->SetStaticMesh(BarricadeMesh.Object);
		doorBarricadeMesh->SetupAttachment(RootComponent);
		doorBarricadeMesh->SetRelativeLocation(FVector(-8.5, 40, 130));
		doorBarricadeMesh->SetRelativeRotation(FRotator(0, 90, 0));
	}
}

void ADoorWalter_a::BeginPlay()
{
	bOpenable = false;
	if (doorBarricadeMesh != nullptr) {
		doorBarricadeMesh->SetVisibility(!bOpenable);
	}
}

void ADoorWalter_a::Tick(float DeltaTime)
{

}

void ADoorWalter_a::Interaction()
{
	if (bOpenable == false) {
		auto gameInstance = Cast<UManagers>(UGameplayStatics::GetGameInstance(GetWorld()));
		if (gameInstance != nullptr) {
			if (gameInstance->HaveKey()) {
				bOpenable = true;
				doorBarricadeMesh->SetVisibility(!bOpenable);
			}
		}
	}
	else {
		bOpen = !bOpen;

		if (bOpen) {
			SetActorRelativeRotation(FRotator(0, 210, 0));
		}
		else {
			SetActorRelativeRotation(FRotator(0, 90, 0));
		}
	}
	
}
