// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorKey.h"
#include <Components/StaticMeshComponent.h>

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
		keyMesh->SetRelativeScale3D(FVector(2));
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
	// GameInstance에게 데이터 보내기 열쇠 먹었다고
	UE_LOG(LogTemp, Log, TEXT("Get Key"));
}
