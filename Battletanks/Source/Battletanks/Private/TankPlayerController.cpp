// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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
	PlayerControlledTank =  Cast<ATank>(GetPawn());
}

void ATankPlayerController::MoveBarrelTowardsCrosshair() {
	return;
}

