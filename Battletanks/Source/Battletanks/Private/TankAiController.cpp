// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"

ATank* ATankAiController::GetPossessedTank() const {

	return Cast<ATank>(GetPawn());

}



