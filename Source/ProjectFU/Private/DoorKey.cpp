// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorKey.h"
#include <Components/StaticMeshComponent.h>
#include "Managers.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ADoorKey::ADoorKey()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	keyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMesh"));
	keyMesh->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TempKeyMesh(TEXT("/Script/Engine.StaticMesh'/Game/FUContent/Mesh/Horror_Starter_Pack/Key_Key.Key_Key'"));
	if (TempKeyMesh.Succeeded()) {
		keyMesh->SetStaticMesh(TempKeyMesh.Object);
		keyMesh->SetRelativeScale3D(FVector(3));
	}
}

// Called when the game starts or when spawned
void ADoorKey::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorKey::Interaction()
{
	auto gameInstance = Cast<UManagers>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (gameInstance != nullptr) {
		gameInstance->AddKey();
		Destroy();
	}
}
