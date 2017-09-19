// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Classes/Kismet/GameplayStatics.h"

#define MUTATE

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * Barrel)
{
	this->Barrel = Barrel;
}

void UTankAimingComponent::AimAtLocation(FVector Location, float LaunchSpeed)
{
	if (!Barrel)
	{
		UE_LOG(LogTemp, Error, TEXT("TankAimingComponent - Barrel Is NULL"));
		return;
	}
	
	FVector ProjectiveVelocity;
	FVector StartLocation;
	FVector BarrelEndLocation = Barrel->GetSocketLocation("EndOfBarrelSocket"); //Will default to component location if fails.

	UGameplayStatics::SuggestProjectileVelocity(this, MUTATE ProjectiveVelocity, BarrelEndLocation, Location, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);

}

