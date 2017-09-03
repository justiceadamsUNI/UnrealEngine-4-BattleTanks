// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAiController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* PlayerControlledTank = nullptr;

	ATank* PosessedTank = nullptr;;

	ATank* GetPossessedTank() const;

	ATank* GetPlayerControlledTank() const;

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	void MoveBarrelTowardsPlayer();
};
