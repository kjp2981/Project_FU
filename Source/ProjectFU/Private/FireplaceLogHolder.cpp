// Fill out your copyright notice in the Description page of Project Settings.


#include "FireplaceLogHolder.h"
#include <Particles/ParticleSystemComponent.h>

AFireplaceLogHolder::AFireplaceLogHolder()
{
	PrimaryActorTick.bCanEverTick = true;

	fireParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticle"));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> FireParticle(TEXT("/Script/Engine.ParticleSystem'/Game/M5VFXVOL2/Particles/Fire/Fire_03.Fire_03'"));
	if (FireParticle.Succeeded()) {
		fireParticle = FireParticle.Object;
		if (fireParticleComp) {
			fireParticleComp->SetupAttachment(RootComponent);
			fireParticleComp->SetRelativeLocation(FVector(0, -5, 16));
			fireParticleComp->SetRelativeScale3D(FVector(0.5));
			fireParticleComp->SetTemplate(fireParticle);
		}
	}
}

void AFireplaceLogHolder::BeginPlay()
{
	Super::BeginPlay();

	if (fireParticleComp) {
		fireParticleComp->SetVisibility(true);
	}

}

void AFireplaceLogHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFireplaceLogHolder::Interaction()
{
	UE_LOG(LogTemp, Log, TEXT("Fire"));
	if (fireParticleComp) {
		fireParticleComp->SetVisibility(!fireParticleComp->IsVisible());
	}
}
