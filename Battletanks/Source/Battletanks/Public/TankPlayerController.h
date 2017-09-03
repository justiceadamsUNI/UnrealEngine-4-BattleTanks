// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* PlayerControlledTank;

	//Will need To update UI BluePrint as well if these 
	//reticle values change. Blueprint doesn't read these values!
	UPROPERTY(EditAnywhere)
	float ReticleXLocationRelativeToScreen = 0.5;

	UPROPERTY(EditAnywhere)
	float ReticleYLocationRelativeToScreen = 0.33333333;

	UPROPERTY(EditAnywhere)
	float ReticleRayMagnitude = 100000; //1KM

	void FindPlayerControlledTank();
	
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	void MoveBarrelTowardsCrosshair();

	bool GetReticleRayHitLocation(FVector& RayHitLocation) const;

	bool GetUserLookDirection(FVector& WorldLocation, FVector& WorldDirection) const;
};
