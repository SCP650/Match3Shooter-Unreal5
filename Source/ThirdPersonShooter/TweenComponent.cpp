#include "TweenComponent.h"

UTweenComponent::UTweenComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UTweenComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get the starting position of the object
	StartPosition = GetOwner()->GetActorLocation();
}

void UTweenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Check if the tween is still in progress
	if (GetWorld()->GetTimeSeconds() < EndTime)
	{
		// Calculate the current position based on the elapsed time
		float ElapsedTime = GetWorld()->GetTimeSeconds() - StartTime;
		float T = ElapsedTime / (EndTime - StartTime);
		FVector CurrentPosition = FMath::Lerp(StartPosition, EndPosition, T);

		// Set the position of the object
		GetOwner()->SetActorLocation(CurrentPosition);
	}
}

void UTweenComponent::TweenToPosition(FVector TargetPosition, float Time)
{
	// Set the start and end positions, as well as the start and end times for the tween
	StartPosition = GetOwner()->GetActorLocation();
	EndPosition = TargetPosition;
	StartTime = GetWorld()->GetTimeSeconds();
	EndTime = StartTime + Time;
}
