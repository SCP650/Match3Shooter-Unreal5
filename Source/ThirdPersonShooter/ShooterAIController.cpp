// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (AIBehavior != nullptr) {
		RunBehaviorTree(AIBehavior);
		AIBlackboard = GetBlackboardComponent();
		AIBlackboard->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
