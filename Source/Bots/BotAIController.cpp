// Fill out your copyright notice in the Description page of Project Settings.

#include "BotAIController.h"
#include "Bot.h"

ABotAIController::ABotAIController()
{
	// Initialize BehaviorTreeComponent, BlackboardComponent

	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BBComp"));
}

void ABotAIController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	// Get the possessed Pawn and check if it's Bot
	ABot* Bot = Cast<ABot>(Pawn);

	if (Bot)
	{
		// If the blackboard is valid initialize the blackboard for the corresponding behavior tree
		if (Bot->BehaviorTree && Bot->BehaviorTree->BlackboardAsset)
		{
			BlackboardComponent->InitializeBlackboard(*(Bot->BehaviorTree->BlackboardAsset));

			// Start the behavior tree which corresponds to the specific character
			BehaviorTreeComponent->StartTree(*Bot->BehaviorTree);
		}
	}
}
