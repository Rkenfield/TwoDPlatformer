// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerCharacter.h"

// Sets default values
APlatformerCharacter::APlatformerCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool APlatformerCharacter::GetApexTimeOfCurve(UCurveFloat* FloatCurve, float& ApexTime)
{
	float StepSize = .001f;
	float CurrentTime = 0.0f;
	float Slope = (FloatCurve->GetFloatValue(CurrentTime + StepSize) - FloatCurve->GetFloatValue(CurrentTime))/(StepSize);
	float MinTime;
	float MaxTime;
	FloatCurve->GetTimeRange(MinTime,MaxTime);
	while (CurrentTime <= MaxTime)
	{
		CurrentTime += StepSize;
		Slope = (FloatCurve->GetFloatValue(CurrentTime + StepSize) - FloatCurve->GetFloatValue(CurrentTime))/(StepSize);
		if(FMath::IsNearlyZero(Slope,.025))
		{
			ApexTime = CurrentTime;
			
			return true;
		}
	}
	ApexTime = -1;
	return false;
	
}

bool APlatformerCharacter::GetApexTimeOfVelocityCurve(UCurveFloat* FloatCurve, float& ApexTime)
{
	float StepSize = .001f;
	float CurrentTime = 0.0f;
	float MinTime;
	float MaxTime;
	FloatCurve->GetTimeRange(MinTime,MaxTime);
	while (CurrentTime <= MaxTime)
	{
		float val = FloatCurve->GetFloatValue(CurrentTime);
		if(FMath::IsNearlyZero(val))
		{
			ApexTime = CurrentTime;
			
			return true;
		}
	}
	ApexTime = -1;
	return false;
}

