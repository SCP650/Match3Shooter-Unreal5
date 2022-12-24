// Fill out your copyright notice in the Description page of Project Settings.


#include "Match3Subsystem.h"

void UMatch3Subsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	if (BP_Sphere != nullptr) {
		SpawnSpheres(5);
	}
	GLog->Log("Match3 Subsystem Inithalized ");
}

void UMatch3Subsystem::Deinitialize()
{
}

void UMatch3Subsystem::SpawnSpheres(int count)
{
	for (int i = 0; i < count; i++) {
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		FRotator myRot(0, 0, 0);
		FVector myLoc(0, i * 50, 0);

		GetWorld()->SpawnActor<ASphereActor>(BP_Sphere, myLoc, myRot, SpawnInfo);
		GLog->Log("Spawned the ASphereActor.");
	}
}

void UMatch3Subsystem::CheckForSameColorSpheres()
{
}
