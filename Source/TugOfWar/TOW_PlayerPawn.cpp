// Fill out your copyright notice in the Description page of Project Settings.


#include "TOW_PlayerPawn.h"

// Sets default values
ATOW_PlayerPawn::ATOW_PlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATOW_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATOW_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATOW_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			// PawnClientRestart can run more than once in an Actor's lifetime, so start by clearing out any leftover mappings.
			Subsystem->ClearAllMappings();

			// Loop through InputMappingContexts array adding them to the subsystem using the array index as the priority.
			for (int32 Index = 0; Index < InputMappingContexts.Num(); ++Index)
			{
				if (InputMappingContexts[Index])
				{
					Subsystem->AddMappingContext(InputMappingContexts[Index], Index);
				}
			}
		}
	}
}

