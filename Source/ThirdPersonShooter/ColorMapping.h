// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class SphereColorEnum : uint8
{
	Blue     UMETA(DisplayName = "Blue"),
	Red      UMETA(DisplayName = "Red"),
	Yellow   UMETA(DisplayName = "Yellow"),
	Green   UMETA(DisplayName = "Green")
};

class THIRDPERSONSHOOTER_API ColorMapping
{
public:
	static TMap<SphereColorEnum, FLinearColor> ColorMap;
	static FLinearColor GetRandomColor();
	static SphereColorEnum GetRandomSphereColorKey();
};

