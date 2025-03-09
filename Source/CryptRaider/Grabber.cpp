// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Animation/AnimInstanceProxy.h"
#include "Engine/World.h"


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

	
}

void UGrabber::Released()
{
	UE_LOG(LogTemp, Display, TEXT("Realeased"));
}

void UGrabber::Grab()
{
	//Draw Debug Line para verificar se pegou alguma coisa
	FVector Start;
	FVector End;
	Start = GetComponentLocation();
	End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false,1);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	// O ECC_GameTraceChannel2 abaixo foi pego indo na DefaultEngine.ini e pesquisando pelo channel grabber que criamos.
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start,End,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Sphere
		);
	if (HasHit)
	{
		AActor* HitActor = HitResult.GetActor();
		UE_LOG(LogTemp, Display, TEXT("HitActor: %s"), *HitActor->GetActorNameOrLabel());
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No Hit"));
	}
}
