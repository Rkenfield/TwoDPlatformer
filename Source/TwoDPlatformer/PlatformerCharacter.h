// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GrappleComponent.h"
#include "GameFramework/Pawn.h"
#include "Curves/CurveFloat.h"
#include "InputActionValue.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "PlatformerCharacter.generated.h"

class UEnhancedInputComponent;

UCLASS()
class TWODPLATFORMER_API APlatformerCharacter : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* RunAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* AttackAction;
public:
	// Sets default values for this pawn's properties
	APlatformerCharacter();

	UPROPERTY(BlueprintReadWrite)
	USceneComponent* WatchPoint;

	UPROPERTY(BlueprintReadWrite)
	USceneComponent* LeftWallTraceOrigin;

	UPROPERTY(BlueprintReadWrite)
	USceneComponent* RightWallTraceOrigin;

	UPROPERTY(BlueprintReadWrite)
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(BlueprintReadWrite)
	UGrappleComponent* GrappleComponent;

	UPROPERTY(BlueprintReadWrite)
	UFloatingPawnMovement* FloatingPawnMovement;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void AttachGrapple(AGrapplePointSwing* GrapplePoint);

	UFUNCTION(BlueprintImplementableEvent)
	void DetachGrapple();
	
private:
	//TODO:Implement
	UFUNCTION()
	void MovementTriggered(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void MovementStarted(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void MovementCanceled(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void MovementCompleted(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void JumpTriggered(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void JumpStarted(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void JumpCanceled(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void JumpCompleted(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void RunTriggered(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void RunCanceled(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void RunCompleted(const FInputActionValue& Value);
	//TODO:Implement
	UFUNCTION()
	void AttackStarted(const FInputActionValue& Value);
	
	//TODO:Implement
	UFUNCTION()
	void MoveLeftRight(float InputValue, float MaxSpeed, float AccelerationMod);
	//TODO:Implement
	UFUNCTION()
	void ResetJumpValues();
	//TODO:Implement
	UFUNCTION()
	bool CheckIfFloorIsBeneathPlayer();
	//TODO:Implement
	UFUNCTION()
	FVector CalculateGravity(FVector UpVector);
	//TODO:Implement
	UFUNCTION()
	FVector AddAccelerationToForwardVelocity(float InputScalar, float AccelerationMod);
	//TODO:Implement
	UFUNCTION()
	bool BoxTraceForPlatform(FVector Start, FVector End);
	//TODO:Implement
	UFUNCTION()
	void MultiAttackAndSlowFallTimer();
	//TODO:Implement
	UFUNCTION()
	void ResetAttackCombo();
	//TODO:Implement
	UFUNCTION()
	void WaitToResetCombo();
	//TODO:Implement
	UFUNCTION()
	void DefaultJump();
	//TODO:Implement
	UFUNCTION()
	FVector ComputeAcceleration();
	//TODO:Implement
	UFUNCTION()
	FVector ComputeVelocity(FVector InitialVelocity, float DeltaTime);
	//TODO:Implement
	UFUNCTION()
	void AddForce(FVector PendingForce);
	//TODO:Implement
	UFUNCTION()
	void ClearPendingForce(bool Immediate);
	//TODO:Implement
	UFUNCTION()
	void MultiTraceForAttack();

	
};
