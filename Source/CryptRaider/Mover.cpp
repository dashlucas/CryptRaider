// Fill out your copyright notice in the Description page of Project Settings.

#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	// Obtém a localização original do ator no início do jogo.
	OriginalLocation = GetOwner()->GetActorLocation();
}
// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (ShouldMove)
	{
		// Obtém a localização atual do ator.
		FVector CurrentLocation = GetOwner()->GetActorLocation();

		// Calcula a localização alvo para o movimento.
		FVector TargetLocation = OriginalLocation + MoveOffset;

		// Calcula a velocidade necessária para atingir o alvo dentro do tempo definido.
		float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;
	
		// Interpola linearmente a localização atual para a localização alvo usando velocidade constante.
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		
		// Aplica a nova localização ao ator para realizar o movimento.
		GetOwner()->SetActorLocation(NewLocation);
	}

}