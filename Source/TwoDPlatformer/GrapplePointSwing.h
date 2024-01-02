// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrapplePointSwing.generated.h"

UCLASS()
class TWODPLATFORMER_API AGrapplePointSwing : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrapplePointSwing();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float SpringConst = 1000;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float DampConst = 100;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MaxRestLen = 600;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	


};
