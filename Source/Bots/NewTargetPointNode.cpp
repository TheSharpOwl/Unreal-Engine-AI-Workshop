// Fill out your copyright notice in the Description page of Project Settings.


#include "NewTargetPointNode.h"
#include "BotAIController.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "Bot.h"

EBTNodeResult::Type UNewTargetPointNode::ExecuteTask(UBehaviorTreeComponent & OwnerComponent, uint8 * NodeMemory)
{
	ABotAIController* AIController = Cast<ABotAIController>(OwnerComponent.GetAIOwner());
	if (AIController)
	{

		ABot* Bot = Cast<ABot>(AIController->GetPawn());

		if (Bot)
		{
			UBlackboardComponent* BlackboardComponent = AIController->GetBBComponent();
			int i = BlackboardComponent->GetValueAsInt(AIController->PatrolPointIndexKey);
			BlackboardComponent->SetValueAsObject(AIController->LocationToGoKey, Bot->GetTargetPointByIndex(i));

			int NextPatrolPointIndex = Bot->GetNextTargetIndex(BlackboardComponent->GetValueAsInt(AIController->PatrolPointIndexKey));

			BlackboardComponent->SetValueAsInt(AIController->PatrolPointIndexKey, NextPatrolPointIndex);

			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}