// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorMapping.h"

TMap<SphereColorEnum, FLinearColor> ColorMapping::ColorMap{
	{ SphereColorEnum::Red, FLinearColor::Red },
	{ SphereColorEnum::Green, FLinearColor::Green },
	{ SphereColorEnum::Blue, FLinearColor::Blue },
	{ SphereColorEnum::Yellow, FLinearColor::Yellow }
};

FLinearColor ColorMapping::GetRandomColor()
{
	int32 Index = FMath::RandRange(0, ColorMap.Num() - 1);
	TArray<SphereColorEnum> keys;
	ColorMapping::ColorMap.GetKeys(keys);
	FLinearColor* Color = ColorMap.Find(keys[Index]);
	return Color ? *Color : FLinearColor::Black;
}

SphereColorEnum ColorMapping::GetRandomSphereColorKey()
{
	int32 Index = FMath::RandRange(0, ColorMap.Num() - 1);
	TArray<SphereColorEnum> keys;
	ColorMapping::ColorMap.GetKeys(keys);
	return keys[Index];
}