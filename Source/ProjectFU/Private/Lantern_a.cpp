// Fill out your copyright notice in the Description page of Project Settings.


#include "Lantern_a.h"
#include "LanternManager.h"
#include <Particles/ParticleSystemComponent.h>
#include <Kismet/GameplayStatics.h>

ALantern_a::ALantern_a()
{
	PrimaryActorTick.bCanEverTick = true;

	lanternLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("LanternLight"));
	if (lanternLight != nullptr) {
		lanternLight->SetupAttachment(RootComponent);
		lanternLight->SetRelativeLocation(FVector(0, 0, 17));
		lanternLight->Intensity = 1000;
		lanternLight->AttenuationRadius = 300;
	}

	candleFireComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("CandleFire"));

	static ConstructorHelpers::FObjectFinder<UParticleSystem> CandleFire(TEXT("/Script/Engine.ParticleSystem'/Game/M5VFXVOL2/Particles/Reference/Candlefire/0_CandleFire_pt.0_CandleFire_pt'"));
	if (CandleFire.Succeeded()) {
		candleFire = CandleFire.Object;
		if (candleFireComp) {
			candleFireComp->SetupAttachment(lanternLight);
			candleFireComp->SetRelativeLocation(FVector(0, 0, -3.5));
			candleFireComp->SetTemplate(candleFire);
		}
	}
}

void ALantern_a::BeginPlay()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), candleFire, FTransform());

	TObjectPtr<AActor> Parent = GetAttachParentActor();
	if (Parent != nullptr) {
		lanternManager = Cast<ALanternManager>(Parent);
	}

	SetVisible(false);
}

void ALantern_a::Tick(float DeltaTime)
{
}

void ALantern_a::Interaction()
{
	// 자신의 랜턴을 칸다음 자신의 id를 lanternmanager에 넘겨
	// lanternmanager는 id를 받은 다음 해당 id의 맞는 다른 id의 랜턴을 켜

	if (lanternManager != nullptr) {
		if (lanternManager->GetComplete() == false) {
			SetVisible(!lanternLight->IsVisible());
		}
	}
	else {
		SetVisible(!lanternLight->IsVisible());
	}
	if (lanternManager != nullptr) {
		lanternManager->SetOtherLanternAutoVisible(GetID());
	}
}

void ALantern_a::SetVisible(bool value)
{
	if (lanternLight != nullptr) {
		lanternLight->SetVisibility(value);
	}
	if (candleFireComp) {
		candleFireComp->SetVisibility(value);
	}
}

void ALantern_a::SetID(int id)
{
	this->iId = id; 
}