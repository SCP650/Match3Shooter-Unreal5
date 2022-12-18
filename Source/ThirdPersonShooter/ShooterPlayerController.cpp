// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	HUDPointer = CreateWidget(this, HUDClass);
	if (HUDPointer != nullptr) {
		HUDPointer->AddToViewport();
	}
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	if (HUDPointer != nullptr) {
		HUDPointer->RemoveFromViewport();
	}
	if (bIsWinner) {
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen != nullptr) {
			WinScreen->AddToViewport();
		}
	}
	else {
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen != nullptr) {
			LoseScreen->AddToViewport();
		}
	}
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);

}


