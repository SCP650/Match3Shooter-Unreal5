// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "ColorMapping.h"

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

	// Check if the mesh is valid
	if (Mesh)
	{
		// Create a dynamic material instance from the static mesh's material
		UMaterialInstanceDynamic* MaterialInstance = Mesh->CreateAndSetMaterialInstanceDynamic(0);

		// Check if the material instance is valid
		if (MaterialInstance)
		{
			FLinearColor Fcolor = * ColorMapping::ColorMap.Find(SphereColor);

			// Set the color parameter of the material to the desired color
			MaterialInstance->SetVectorParameterValue("Color", Fcolor);
		}
	}
}

void ASphereActor::TakeDamage(float damage)
{
	currHealth -= damage;
	if (currHealth < 0) {
		Destroy(true);
	}
}

