// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SphereActor.h"
#include "Subsystems/WorldSubsystem.h"
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
private:
	void SpawnSpheres(int count);
	void CheckForSameColorSpheres();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASphereActor> BP_Sphere;
};
