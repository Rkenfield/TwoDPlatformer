// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Curves/CurveFloat.h"
#include "PlatformerCharacter.generated.h"

UCLASS()
class TWODPLATFORMER_API APlatformerCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlatformerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	bool GetApexTimeOfCurve(UCurveFloat* FloatCurve, float& ApexTime);
	
	UFUNCTION(BlueprintPure)
    bool GetApexTimeOfVelocityCurve(UCurveFloat* FloatCurve, float& ApexTime);

};
