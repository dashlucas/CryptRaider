// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Draw Debug Line
	FVector Start;
	FVector End;
	UCameraComponent* CameraComponent = GetOwner()->FindComponentByClass<UCameraComponent>();
	if (CameraComponent)
	{
		Start = GetOwner()->GetActorLocation();
		End = (CameraComponent->GetForwardVector() * MaxGrabDistance) + Start;
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false,1);
	}
	
}

