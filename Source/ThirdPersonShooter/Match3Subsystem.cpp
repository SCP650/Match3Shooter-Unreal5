// Fill out your copyright notice in the Description page of Project Settings.


#include "Match3Subsystem.h"
#include "ColorMapping.h"

#define M_PI 3.14159265358979323846

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

		GLog->Log("sphere bp is not null ");
		SpawnSpheres(2355,-2930,180,1000,200);
	}
	else {

		GLog->Log("sphere bp is null ");
	}
}

void UMatch3Subsystem::SpawnSpheres(float CenterX, float CenterY, float Degree, float CircleRadius, float ObjectRadius)
{
	GLog->Log("spawning sphere");
	FRotator myRot(0, 0, 0);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	// Calculate the maximum number of objects that can fit in the specified degree range
   // by dividing the degree range by the diameter of the object
	int MaxObjectCount = static_cast<int>(FMath::Floor(Degree * M_PI * CircleRadius / (180.0f * ObjectRadius)));

	// Calculate the angle between each object
	float AngleBetweenObjects = Degree / MaxObjectCount;

	// Calculate the starting angle based on the degree parameter
	float StartingAngle = 0;

	// Place the objects on the circumference
	for (int i = 0; i < MaxObjectCount; i++)
	{
		float Angle = StartingAngle + i * AngleBetweenObjects;
		float Radians = Angle * M_PI / 180.0f;

		float X = CenterX + CircleRadius * FMath::Cos(Radians);
		float Y = CenterY + CircleRadius * FMath::Sin(Radians);

		FVector myLoc(X, Y, 50);
		ASphereActor* sphere = GetWorld()->SpawnActor<ASphereActor>(BP_Sphere, myLoc, myRot, SpawnInfo);
		sphere->SetColor(ColorMapping::GetRandomSphereColorKey());
		sphere->id = i;
		SpherePositions.Add(sphere);
		GLog->Log("Spawned the ASphereActor.");
	}


}

void UMatch3Subsystem::CheckForSameColorSpheres()
{
}

void UMatch3Subsystem::OnSphereDestroyed(int id)
{
	GLog->Log("sphere destroyed!!!");
	for(int i = id+1; i < SpherePositions.Num(); i++)
	{
		//get previous sphere loc
		FVector target = SpherePositions[i-1]->GetActorLocation();
		//move up
		SpherePositions[i]->MoveToPosition(target, 1);
		SpherePositions[i]->id = i-1;
	}
	SpherePositions.RemoveAt(id);
}
