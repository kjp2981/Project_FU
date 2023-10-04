// Fill out your copyright notice in the Description page of Project Settings.


#include "FrontDoor_a.h"
#include <Kismet/GameplayStatics.h>
#include <Components/BoxComponent.h>
#include "Managers.h"

AFrontDoor_a::AFrontDoor_a()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarricadeMesh(TEXT("/Script/Engine.StaticMesh'/Game/EF_FirstFloor/Meshes/DoorBarricade_a.DoorBarricade_a'"));
	if (BarricadeMesh.Succeeded()) {
		doorBarricadeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Barricade"));
		doorBarricadeMesh->SetStaticMesh(BarricadeMesh.Object);
		doorBarricadeMesh->SetupAttachment(RootComponent);
		doorBarricadeMesh->SetRelativeLocation(FVector(-8.5, 40, 130));
		doorBarricadeMesh->SetRelativeRotation(FRotator(0, 90, 0));
	}

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	if (boxComp) {
		boxComp->SetupAttachment(RootComponent);
		boxComp->SetRelativeLocation(FVector(0, 41, 105));
		boxComp->SetRelativeScale3D(FVector(0.1, 1.3, 3.3));
	}
}

void AFrontDoor_a::BeginPlay()
{
	/*if (boxComp) {
		boxComp->OnComponentBeginOverlap.AddDynamic(this, &AFrontDoor_a::OnBoxComponentOverlapBegin);
	}*/

	// 몇초 후에 승리 표시
}

void AFrontDoor_a::Tick(float DeltaTime)
{
}

void AFrontDoor_a::Interaction()
{
	if (bOpenable == false) {
		auto gameInstance = Cast<UManagers>(UGameplayStatics::GetGameInstance(GetWorld()));
		if (gameInstance != nullptr) {
			if (gameInstance->GetKeyNum() > 1) {
				bOpenable = true;
				doorBarricadeMesh->SetVisibility(!bOpenable);
			}
		}
	}
	else {
		bOpen = !bOpen;

		if (bOpen) {
			SetActorRelativeRotation(FRotator(0, 210, 0));
			//OnScreenEffect();
			
			auto gameInstance = Cast<UManagers>(UGameplayStatics::GetGameInstance(GetWorld()));
			if (gameInstance != nullptr) {
				gameInstance->AddClearUI();
			}
		}
		else {
			SetActorRelativeRotation(FRotator(0, 90, 0));
		}
	}
}

void AFrontDoor_a::OpenDoor(bool value)
{
	
}

void AFrontDoor_a::OnBoxComponentOverlapBegin(AActor* OverlappedActor, UPrimitiveComponent* OverlappedComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto gameInstance = Cast<UManagers>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (gameInstance != nullptr) {
		gameInstance->AddClearUI();
	}
}