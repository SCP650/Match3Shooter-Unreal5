// Fill out your copyright notice in the Description page of Project Settings.


#include "Match3Subsystem.h"
#include "ColorMapping.h"

void UMatch3Subsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	GLog->Log("Match3 Subsystem Inithalized ");

}

void UMatch3Subsystem::Deinitialize()
{
	GLog->Log("Match3 Subsystem deinitialized ");
}

void UMatch3Subsystem::SetSphereActor(TSubclassOf<class ASphereActor> SphereClass)
{
	GLog->Log("Set sphere called ");
	BP_Sphere = SphereClass;
	if (BP_Sphere != nullptr) {
		SpawnSpheres(5);
	}
}

void UMatch3Subsystem::SpawnSpheres(int count)
{
	for (int i = 0; i < count; i++) {
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		FRotator myRot(0, 0, 0);
		FVector myLoc(2400.000000 + i * 100,-750.000000,50);

		ASphereActor* sphere = GetWorld()->SpawnActor<ASphereActor>(BP_Sphere, myLoc, myRot, SpawnInfo);
		sphere->SetColor(ColorMapping::GetRandomSphereColorKey());
		GLog->Log("Spawned the ASphereActor.");
	}
}

void UMatch3Subsystem::CheckForSameColorSpheres()
{
}
