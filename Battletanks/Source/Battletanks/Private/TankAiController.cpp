// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

void ATankAiController::BeginPlay() {
	if (!GetPossessedTank())
	{
		UE_LOG(LogTemp, Error, TEXT("Tank AI Controller Started. Error: Possesed Tank IS NULL"));
	}

	if (GetPlayerControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller Started. Player Pawn is : %s"), *GetPlayerControlledTank()->GetName());
	}
}

ATank* ATankAiController::GetPossessedTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerControlledTank() const {
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		return Cast<ATank>(PlayerController->GetPawn());
	}
	
	return nullptr;
}



