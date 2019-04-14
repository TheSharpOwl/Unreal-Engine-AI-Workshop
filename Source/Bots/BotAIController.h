// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "BotAIController.generated.h"

/**
 * 
 */
UCLASS()
class BOTS_API ABotAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	// AI components
	UBehaviorTreeComponent* BehaviorTreeComponent;
	UBlackboardComponent* BlackboardComponent;

	/* Posses is executed when the character we want to control is spawned.
	Inside this function, we initialize the blackboard and start the behavior tree */
	virtual void Possess(APawn* Pawn) override;// Important Note in the newer version it's called OnPossess
public:
	ABotAIController();

	// Blackboard key name to store the location where Bot should move
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName LocationToGoKey = "LocationToGo";

	// Blackboard key name to store the location where Bot should move
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName PatrolPointIndexKey = "PatrolPointIndex";

	UBlackboardComponent* GetBBComponent() { return BlackboardComponent; }
};
