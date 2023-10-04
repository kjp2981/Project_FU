// Fill out your copyright notice in the Description page of Project Settings.


#include "CandleHolder.h"
#include <Particles/ParticleSystemComponent.h>
#include <Components/PointLightComponent.h>

// Sets default values
ACandleHolder::ACandleHolder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CandleHolderMesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> CandleHolderMesh(TEXT("/Script/Engine.StaticMesh'/Game/EF_Edie/Meshes/CandleHolder_a.CandleHolder_a'"));
	if (CandleHolderMesh.Succeeded()) {
		if (staticMeshComp) {
			staticMeshComp->SetStaticMesh(CandleHolderMesh.Object);
		}
	}

	RootComponent = staticMeshComp;

	fireParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("CandleFireParticle"));

	ConstructorHelpers::FObjectFinder<UParticleSystem> CandleFireParticle(TEXT("/Script/Engine.ParticleSystem'/Game/M5VFXVOL2/Particles/Reference/Candlefire/0_CandleFire_pt.0_CandleFire_pt'"));
	if (CandleFireParticle.Succeeded()) {
		fireParticle = CandleFireParticle.Object;
		if (fireParticleComp) {
			fireParticleComp->SetTemplate(fireParticle);
			fireParticleComp->SetupAttachment(RootComponent);
			fireParticleComp->SetRelativeLocation(FVector(0, 0, 57));
		}
	}

	lightComp = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightComp"));
	if (lightComp) {
		lightComp->SetupAttachment(RootComponent);
		lightComp->SetRelativeLocation(FVector(0, 0, 63));
		lightComp->Intensity = 700;
	}
}

// Called when the game starts or when spawned
void ACandleHolder::BeginPlay()
{
	Super::BeginPlay();
	
	lightComp->SetVisibility(bTurnOn);
	fireParticleComp->SetVisibility(bTurnOn);
}

// Called every frame
void ACandleHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACandleHolder::Interaction()
{
	bTurnOn = !bTurnOn;

	if (bTurnOn) {
		lightComp->SetVisibility(true);
		fireParticleComp->SetVisibility(true);
	}
	else {
		lightComp->SetVisibility(false);
		fireParticleComp->SetVisibility(false);
	}
}

