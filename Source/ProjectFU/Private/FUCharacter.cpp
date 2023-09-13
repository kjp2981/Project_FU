// Fill out your copyright notice in the Description page of Project Settings.


#include "FUCharacter.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <GameFramework/CharacterMovementComponent.h>
#include "IInteractable.h"
#include "Managers.h"

// Sets default values
AFUCharacter::AFUCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	if (springArmComp) {
		springArmComp->SetupAttachment(RootComponent);
	}
	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CamComp"));
	if (cameraComp) {
		cameraComp->SetupAttachment(springArmComp);
		cameraComp->SetRelativeLocation(FVector(0));
	}
}

// Called when the game starts or when spawned
void AFUCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	springArmComp->bUsePawnControlRotation = true;
	GetCharacterMovement()->MaxWalkSpeed = 400;
	params.AddIgnoredActor(this);

	auto manager = Cast<UManagers>(GetGameInstance());
	manager->AddMainUI();
}

// Called every frame
void AFUCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector startPos = cameraComp->GetComponentLocation();
	FVector endPos = startPos + cameraComp->GetForwardVector() * 200;
	bHit = GetWorld()->LineTraceSingleByChannel(hitInfo, startPos, endPos, ECC_Visibility, params);
}

// Called to bind functionality to input
void AFUCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* playerController = Cast<APlayerController>(Controller);
	if (playerController) {
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
		if (subsystem) {
			subsystem->AddMappingContext(imc, 0);
		}
	}

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		enhancedInputComponent->BindAction(moveForwardAction, ETriggerEvent::Triggered, this, &AFUCharacter::MoveForward);
		enhancedInputComponent->BindAction(moveRightAction, ETriggerEvent::Triggered, this, &AFUCharacter::MoveRight);

		enhancedInputComponent->BindAction(turnPitchAction, ETriggerEvent::Triggered, this, &AFUCharacter::TurnPitch);
		enhancedInputComponent->BindAction(turnYawAction, ETriggerEvent::Triggered, this, &AFUCharacter::TurnYaw);

		enhancedInputComponent->BindAction(runAction, ETriggerEvent::Triggered, this, &AFUCharacter::Run);

		enhancedInputComponent->BindAction(interactionAction, ETriggerEvent::Triggered, this, &AFUCharacter::Interaction);

		enhancedInputComponent->BindAction(crouchAction, ETriggerEvent::Triggered, this, &AFUCharacter::Crouch);
	}
}

void AFUCharacter::MoveForward(const FInputActionValue& value)
{
	float movement = value.Get<float>();
	if (Controller != nullptr) {
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator yawRotation(0, rotation.Yaw, 0);

		const FVector forwardDir = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(forwardDir, movement);
	}
}

void AFUCharacter::MoveRight(const FInputActionValue& value)
{
	float movement = value.Get<float>();
	if (Controller != nullptr) {
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator yawRotation(0, rotation.Yaw, 0);

		const FVector rightDir = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(rightDir, movement);
	}
}

void AFUCharacter::TurnPitch(const FInputActionValue& value)
{
	float rot = -value.Get<float>();

	if (Controller != nullptr) {
		AddControllerPitchInput(rot);
	}
}

void AFUCharacter::TurnYaw(const FInputActionValue& value)
{
	float rot = value.Get<float>();

	if (Controller != nullptr) {
		AddControllerYawInput(rot);
	}
}

void AFUCharacter::Run(const FInputActionValue& value)
{
	bool run = value.Get<bool>();

	bRun = run;

	auto movement = GetCharacterMovement();
	if (bRun) {
		movement->MaxWalkSpeed = 600;
	}
	else {
		movement->MaxWalkSpeed = 400;
	}
}

void AFUCharacter::Interaction(const FInputActionValue& value)
{
	if (bHit) {
		// 뭔가 상호작용이 있으면 하기
		if (hitInfo.GetActor()->GetClass()->ImplementsInterface(UIInteractable::StaticClass())) {
			auto interactable = Cast<IIInteractable>(hitInfo.GetActor());
			interactable->Interaction();
		}
	}
}

void AFUCharacter::Crouch(const FInputActionValue& value)
{
	bCrouch = !bCrouch;

	if (bCrouch) {
		// 카메라 내리기
		cameraComp->SetRelativeLocation(FVector(0, 0, -70));
	}
	else {
		// 카메라 올리기
		cameraComp->SetRelativeLocation(FVector(0));
	}
}

