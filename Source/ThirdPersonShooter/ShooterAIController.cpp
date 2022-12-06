// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (LineOfSightTo(PlayerPawn)) {
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn, AcceptanceRadius, false);
	}
	else {
		StopMovement();
		ClearFocus(EAIFocusPriority::Gameplay);
	}
	
}
