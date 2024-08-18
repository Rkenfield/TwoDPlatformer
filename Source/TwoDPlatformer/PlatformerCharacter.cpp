// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerCharacter.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
// Sets default values
APlatformerCharacter::APlatformerCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WatchPoint = CreateDefaultSubobject<USceneComponent>("WatchPoint");
	WatchPoint->SetupAttachment(RootComponent);
	LeftWallTraceOrigin = CreateDefaultSubobject<USceneComponent>("LeftWallTraceOrigin");
	LeftWallTraceOrigin->SetupAttachment(RootComponent);
	RightWallTraceOrigin = CreateDefaultSubobject<USceneComponent>("RightWallTraceOrigin");
	RightWallTraceOrigin->SetupAttachment(RootComponent);
	SkeletalMesh->CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(RootComponent);
	GrappleComponent->CreateDefaultSubobject<UGrappleComponent>("GrappleComponent");
	FloatingPawnMovement->CreateDefaultSubobject<UFloatingPawnMovement>("FloatingPawnMovement");
}

// Called when the game starts or when spawned
void APlatformerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlatformerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Move Inputs
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Started,this,&APlatformerCharacter::MovementStarted);
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&APlatformerCharacter::MovementTriggered);
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Canceled,this,&APlatformerCharacter::MovementCanceled);
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Completed,this,&APlatformerCharacter::MovementCompleted);
		//Jump Inputs
		EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this,&APlatformerCharacter::JumpStarted);
		EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Triggered,this,&APlatformerCharacter::JumpTriggered);
		EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Canceled,this,&APlatformerCharacter::JumpCanceled);
		EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed,this,&APlatformerCharacter::JumpCompleted);
		//Run Inputs
		EnhancedInputComponent->BindAction(RunAction,ETriggerEvent::Triggered,this,&APlatformerCharacter::RunTriggered);
		EnhancedInputComponent->BindAction(RunAction,ETriggerEvent::Canceled,this,&APlatformerCharacter::RunCanceled);
		EnhancedInputComponent->BindAction(RunAction,ETriggerEvent::Completed,this,&APlatformerCharacter::RunCompleted);
		//Attack Inputs
		EnhancedInputComponent->BindAction(AttackAction,ETriggerEvent::Started,this,&APlatformerCharacter::AttackStarted);
	}

}
//Move Inputs
void APlatformerCharacter::MovementTriggered(const FInputActionValue& Value)
{
}

void APlatformerCharacter::MovementStarted(const FInputActionValue& Value)
{
}

void APlatformerCharacter::MovementCanceled(const FInputActionValue& Value)
{
}

void APlatformerCharacter::MovementCompleted(const FInputActionValue& Value)
{
}
//Jump Inputs
void APlatformerCharacter::JumpTriggered(const FInputActionValue& Value)
{
}

void APlatformerCharacter::JumpStarted(const FInputActionValue& Value)
{
}

void APlatformerCharacter::JumpCanceled(const FInputActionValue& Value)
{
}

void APlatformerCharacter::JumpCompleted(const FInputActionValue& Value)
{
}
//Run Inputs
void APlatformerCharacter::RunTriggered(const FInputActionValue& Value)
{
}

void APlatformerCharacter::RunCanceled(const FInputActionValue& Value)
{
}

void APlatformerCharacter::RunCompleted(const FInputActionValue& Value)
{
}
//Attack Inputs
void APlatformerCharacter::AttackStarted(const FInputActionValue& Value)
{
}

//UTILITY FUNCTIONS
void APlatformerCharacter::MoveLeftRight(float InputValue, float MaxSpeed, float AccelerationMod)
{
}

void APlatformerCharacter::ResetJumpValues()
{
}

bool APlatformerCharacter::CheckIfFloorIsBeneathPlayer()
{
	return false;
}

FVector APlatformerCharacter::CalculateGravity(FVector UpVector)
{
	return FVector::Zero();
}

FVector APlatformerCharacter::AddAccelerationToForwardVelocity(float InputScalar, float AccelerationMod)
{
	return FVector::Zero();
}

bool APlatformerCharacter::BoxTraceForPlatform(FVector Start, FVector End)
{
	return false;
}

void APlatformerCharacter::MultiAttackAndSlowFallTimer()
{
}

void APlatformerCharacter::ResetAttackCombo()
{
}

void APlatformerCharacter::WaitToResetCombo()
{
}

void APlatformerCharacter::DefaultJump()
{
}

FVector APlatformerCharacter::ComputeAcceleration()
{
	return FVector::Zero();
}

FVector APlatformerCharacter::ComputeVelocity(FVector InitialVelocity, float DeltaTime)
{
	return FVector::Zero();
}

void APlatformerCharacter::AddForce(FVector PendingForce)
{
}

void APlatformerCharacter::ClearPendingForce(bool Immediate)
{
}

void APlatformerCharacter::MultiTraceForAttack()
{
}

