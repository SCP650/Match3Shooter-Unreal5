// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorMapping.h"
#include "TweenComponent.h"
#include "SphereActor.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API ASphereActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASphereActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
		int id = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		SphereColorEnum SphereColor;
	UPROPERTY(EditAnywhere)
		float MaxHealth;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> gc_class;

	float currHealth;
	void SetColor(SphereColorEnum color);
	void TakeDamage(float damage);
	void MoveToPosition(FVector loc, float duration);
	void DestroyBySubSystem();
private:
	UTweenComponent* tween;


};
