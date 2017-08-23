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

	}
}

bool ATankPlayerController::GetReticleRayHitLocation(FVector& RayHitLocation) const {
	int32 ScreenSizeX, ScreenSizeY;
	GetViewportSize(MUTATE ScreenSizeX, MUTATE ScreenSizeY);

	FVector2D ReticleLocation = FVector2D(ScreenSizeX * ReticleXLocationRelativeToScreen, ScreenSizeY * ReticleYLocationRelativeToScreen);

	FVector WorldLocation, WorldDirection;

	bool hit = DeprojectScreenPositionToWorld(ReticleLocation.X, ReticleLocation.Y, WorldLocation, WorldDirection);

	if (hit) {
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller. WORLD DIRECTION Location X = %f, Y = %f, Z = %f"), WorldDirection.X, WorldDirection.Y, WorldDirection.Z)

		FVector camera = PlayerCameraManager->GetCameraLocation();
		FVector temp = camera + WorldDirection*1000;
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller. CAMERA Location X = %f, Y = %f, Z = %f"), camera.X, camera.Y, camera.Z);
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller. TEMP Location X = %f, Y = %f, Z = %f"), temp.X, temp.Y, temp.Z);
		DrawDebugLine(GetWorld(), camera, temp, FColor(255, 50, 0), false, 0.0f, 0.0f, 10.0f);
	}

	return false;
}

