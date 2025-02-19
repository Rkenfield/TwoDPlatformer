// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HittableInterface.h"
#include "GameFramework/Pawn.h"
#include "EnemyAI.generated.h"

UCLASS()
class TWODPLATFORMER_API AEnemyAI : public APawn, public IHittableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyAI();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health = 100;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
