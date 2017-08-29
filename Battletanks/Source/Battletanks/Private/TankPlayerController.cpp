// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Public/CollisionQueryParams.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#define MUTATE

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	FindPlayerControlledTank();

	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank Player Controller Started. Error: Possesed Tank IS NULL"));
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (PlayerControlledTank)
	{
		MoveBarrelTowardsCrosshair();
	}
}

void ATankPlayerController::FindPlayerControlledTank() {
	PlayerControlledTank = Cast<ATank>(GetPawn());
}

void ATankPlayerController::MoveBarrelTowardsCrosshair() {
	FVector RayHitLocation = FVector();
	if (GetReticleRayHitLocation(RayHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller. Hit Location X = %f, Y = %f, Z = %f"), RayHitLocation.X, RayHitLocation.Y, RayHitLocation.Z);

	}
}

/*Determines weather a players reticle is hitting a visible object. If so, adjust the RayHitLocation param to that collision location and returns true.*/
bool ATankPlayerController::GetReticleRayHitLocation(FVector& RayHitLocation) const {
	FVector WorldLocation, WorldDirection;
	bool UserLookDirection = GetUserLookDirection(WorldLocation, WorldDirection);
	
	bool HitDetected;
	if (UserLookDirection) {
		FVector CameraLocation = PlayerCameraManager->GetCameraLocation();
		FVector VectorEnd = CameraLocation + WorldDirection*ReticleRayMagnitude;
		
		FHitResult HitResult;
		HitDetected = GetWorld()->LineTraceSingleByChannel(
			MUTATE HitResult, 
			CameraLocation, VectorEnd, 
			ECollisionChannel::ECC_Visibility);

		if (HitDetected) {
			RayHitLocation = HitResult.Location;
		}
	}

	return HitDetected;
}

/*Deprojects vector through the screen at the reticle location. Returns boolean to determine success.*/
bool ATankPlayerController::GetUserLookDirection(FVector& WorldLocation, FVector& WorldDirection) const
{
	int32 ScreenSizeX, ScreenSizeY;
	GetViewportSize(MUTATE ScreenSizeX, MUTATE ScreenSizeY);
	
	FVector2D ReticleLocation = FVector2D(ScreenSizeX * ReticleXLocationRelativeToScreen, ScreenSizeY * ReticleYLocationRelativeToScreen);
	return DeprojectScreenPositionToWorld(ReticleLocation.X, ReticleLocation.Y, WorldLocation, WorldDirection);
}