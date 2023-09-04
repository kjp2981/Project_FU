// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C:/Program Files/Epic Games/UE_5.1/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/InputActionValue.h"
#include "FUCharacter.generated.h"

UCLASS()
class AFUCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFUCharacter();

public:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* springArmComp;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* cameraComp;

	UPROPERTY(VisibleAnywhere, Category = Movement)
	bool isRun = false;
protected:
#pragma region Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* imc;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* moveForwardAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* moveRightAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* turnPitchAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* turnYawAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* runAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* interactionAction;
#pragma endregion

	FHitResult hitInfo;
	FCollisionQueryParams params;
	bool bHit;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveForward(const FInputActionValue& value);
	void MoveRight(const FInputActionValue& value);

	void TurnPitch(const FInputActionValue& value);
	void TurnYaw(const FInputActionValue& value);

	void Run(const FInputActionValue& value);

	void Interaction(const FInputActionValue& value);
};
