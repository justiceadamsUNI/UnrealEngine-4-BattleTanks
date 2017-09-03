// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Classes/Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

void ATankAiController::BeginPlay() {
	Super::BeginPlay();

	PlayerControlledTank = GetPlayerControlledTank();
	PosessedTank = GetPossessedTank();

	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank AI Controller Started. Player Controlled Tank Is NULL"));
	}

	if (!PosessedTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Tank AI Controller Started. Error: Possesed Tank IS NULL"));
	}
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerControlledTank && PosessedTank)
	{
		MoveBarrelTowardsPlayer();
	}
}

void ATankAiController::MoveBarrelTowardsPlayer()
{
	PosessedTank->AimBarrelAt(PlayerControlledTank->GetActorLocation());
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



