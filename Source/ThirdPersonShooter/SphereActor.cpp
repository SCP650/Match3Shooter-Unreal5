// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Match3Subsystem.h"
#include "ColorMapping.h"
#include "GeometryCollection/GeometryCollectionComponent.h"

// Sets default values
ASphereActor::ASphereActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ASphereActor::BeginPlay()
{
	Super::BeginPlay();
	currHealth = MaxHealth;
	tween = FindComponentByClass<UTweenComponent>();
}

// Called every frame
void ASphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASphereActor::SetColor(SphereColorEnum color)
{
	SphereColor = color;
	// Get the static mesh component of the actor
	UStaticMeshComponent* Mesh = FindComponentByClass<UStaticMeshComponent>();
	FLinearColor Fcolor = *ColorMapping::ColorMap.Find(SphereColor);
	// Check if the mesh is valid
	if (Mesh)
	{
		for (int i = 0; i < Mesh->GetNumMaterials(); i++) {
			// Create a dynamic material instance from the static mesh's material
			UMaterialInstanceDynamic* MaterialInstance = Mesh->CreateAndSetMaterialInstanceDynamic(i);

			// Check if the material instance is valid
			if (MaterialInstance)
			{
				// Set the color parameter of the material to the desired color
				MaterialInstance->SetVectorParameterValue("Color", Fcolor);
			}
		}
	}
}

void ASphereActor::TakeDamage(float damage)
{
	currHealth -= damage;
	if (currHealth < 0) {
		//destroyed by player
		GetWorld()->GetSubsystem<UMatch3Subsystem>()->OnSphereDestroyed(id);
	}
}

void ASphereActor::DestroyBySubSystem() {
	
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	FVector myLoc = GetActorLocation();
	FRotator myRot(0, 0, 0);
	AActor* sphere = GetWorld()->SpawnActor<AActor>(gc_class, myLoc, myRot, SpawnInfo);
	// Get the static mesh component of the actor
	UGeometryCollectionComponent* Mesh = sphere->FindComponentByClass<UGeometryCollectionComponent>();

	// Check if the mesh is valid
	if (Mesh)
	{
		// Create a dynamic material instance from the static mesh's material
		UMaterialInstanceDynamic* MaterialInstance = Mesh->CreateAndSetMaterialInstanceDynamic(0);

		// Check if the material instance is valid
		if (MaterialInstance)
		{
			FLinearColor Fcolor = *ColorMapping::ColorMap.Find(SphereColor);

			// Set the color parameter of the material to the desired color
			MaterialInstance->SetVectorParameterValue("Color", Fcolor);
		}
	}

	Destroy(true);
}

void ASphereActor::MoveToPosition(FVector loc, float duration)
{
	if (tween != nullptr) {
		tween->TweenToPosition(loc, duration);
	}
}


