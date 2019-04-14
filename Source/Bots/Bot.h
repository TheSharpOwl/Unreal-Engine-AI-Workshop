// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/TargetPoint.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Bot.generated.h"


UCLASS()
class BOTS_API ABot : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Target points
	UPROPERTY(EditAnywhere, Category = "AI")
	TArray<ATargetPoint*> TargetPoints;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// BTree class to be used in AICotroller for this Bot
	UPROPERTY(EditAnywhere, Category = "AI")
	class UBehaviorTree* BehaviorTree;

	int GetNextTargetIndex(int32 CurrentIndex);

	ATargetPoint* GetTargetPointByIndex(int32 i)
	{
		return i >= 0 && i < TargetPoints.Num() ? TargetPoints[i] : nullptr;  
	};
};
