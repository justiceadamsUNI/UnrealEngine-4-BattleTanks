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

	void FindPlayerControlledTank();
	
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	void MoveBarrelTowardsCrosshair();
	
};
