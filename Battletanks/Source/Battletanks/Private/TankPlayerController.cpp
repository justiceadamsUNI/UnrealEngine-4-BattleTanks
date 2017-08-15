// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	if (!GetPlayerControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("Tank Player Controller Started. Error: Possesed Tank IS NULL"));
	}
}

ATank* ATankPlayerController::GetPlayerControlledTank() const {
	return Cast<ATank>(GetPawn());
}

