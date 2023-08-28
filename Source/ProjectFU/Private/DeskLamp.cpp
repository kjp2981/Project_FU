// Fill out your copyright notice in the Description page of Project Settings.


#include "DeskLamp.h"

// Sets default values
ADeskLamp::ADeskLamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeskLamp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeskLamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

