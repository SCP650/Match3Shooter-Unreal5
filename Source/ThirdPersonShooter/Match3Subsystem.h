// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SphereActor.h"
#include "Match3Subsystem.generated.h"


/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UMatch3Subsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	// USubsystem implementation Begin
	void Initialize(FSubsystemCollectionBase& Collection) override;
	// USubsystem implementation End
	void Deinitialize() override;
	UFUNCTION(BlueprintCallable)
	void SetSphereActor(TSubclassOf<class ASphereActor> SphereClass);
	void OnSphereDestroyed(int start, int count = 1); //destory count number of sphere starting from start

private:
	void SpawnSpheres(float CenterX, float CenterY, float Degree, float CircleRadius, float ObjectRadius);
	void CheckForSameColorSpheres();
	TSubclassOf<class ASphereActor> BP_Sphere;
	TArray<ASphereActor*> SpherePositions;
	bool bIsCheckingForSameColorSpheres = false;
	FTimerHandle Match3TimerHandle;
	
};


