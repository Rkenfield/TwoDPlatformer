// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleComponent.h"

#include "PlatformerCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values for this component's properties
UGrappleComponent::UGrappleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrappleComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrappleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector UGrappleComponent::GetSpringForceFirstImplementation()
{
	if(!GrapplePointSwing || !IsGrappled)return FVector(0,0,0);
	APlatformerCharacter* ownerCharacter = Cast<APlatformerCharacter>(GetOwner());
	FVector VA = FVector(0,0,0);
	FVector VB = ownerCharacter->GetMovementComponent()->Velocity;
	FVector PA = GrapplePointSwing->GetActorLocation();
	FVector PB = GetOwner()->GetActorLocation();
	FVector PosOffset = PA - PB;
	float springConst = GrapplePointSwing->SpringConst;
	float dampConst = GrapplePointSwing->DampConst;
	float maxLen = GrapplePointSwing->MaxRestLen;
	FVector TotalForce = -(springConst * FMath::Max(PosOffset.Length() - maxLen,0) + dampConst * ((VA - VB).Dot(PosOffset))/PosOffset.Length()) * (PosOffset/PosOffset.Length());
	
	return FVector(TotalForce.X,0,TotalForce.Z);
	
	
}

bool UGrappleComponent::BeginGrapple()
{
	if(GrapplePointSwing != nullptr)
	{
		IsGrappled = true;
	}
	return IsGrappled;
}

void UGrappleComponent::EndGrapple()
{
	IsGrappled = false;
}


