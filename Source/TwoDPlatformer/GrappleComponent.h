// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GrapplePointSwing.h"
#include "Components/ActorComponent.h"
#include "GrappleComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TWODPLATFORMER_API UGrappleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrappleComponent();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AGrapplePointSwing* GrapplePointSwing;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool IsGrappled = false;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;\

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintPure)
	FVector GetSpringForceFirstImplementation();

	UFUNCTION(BlueprintCallable)
	bool BeginGrapple();

	UFUNCTION(BlueprintCallable)
	void EndGrapple();
};
