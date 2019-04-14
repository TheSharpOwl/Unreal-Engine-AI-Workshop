// Fill out your copyright notice in the Description page of Project Settings.

#include "Bot.h"

// Sets default values
ABot::ABot()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int ABot::GetNextTargetIndex(int32 CurrentIndex)
{
	int32 NextIndex = CurrentIndex + 1;

	if (NextIndex >= 0 && NextIndex < TargetPoints.Num())
	{
		return NextIndex;
	}
	else
	{
		return 0;
	}
}
