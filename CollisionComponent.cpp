#include "stdafx.h"
#include "CollisionComponent.h"
#include "Engine.h"
#include "World.h"
#include "Actor.h"

UCollisionComponent::UCollisionComponent()
	: bIsGenerateOverlap(false), bIsGenerateHit(false)
{
}

UCollisionComponent::~UCollisionComponent()
{
}

void UCollisionComponent::BeginPlay()
{
}

void UCollisionComponent::Tick()
{
	for (auto Other : GEngine->GetWorld()->GetAllActorsOfClass())
	{
		if (Other == this->Owner)
		{
			continue;
		}

		for (auto OtherComponent : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				if (OtherCollision->bIsGenerateHit &&
					Owner->GetActorLocation().X == Other->GetActorLocation().X
					&& Owner->GetActorLocation().Y == Other->GetActorLocation().Y)
				{
					Other->ReceiveHit(Owner);
					Owner->ReceiveHit(Other);
				}

				if (OtherCollision->bIsGenerateOverlap &&
					Owner->GetActorLocation().X == Other->GetActorLocation().X
					&& Owner->GetActorLocation().Y == Other->GetActorLocation().Y)
				{
					if (Owner->OnActorBeginOverlap)
					{
						Owner->OnActorBeginOverlap(Other);
					}
					if (Other->OnActorBeginOverlap)
					{
						Other->OnActorBeginOverlap(Owner);
					}
				}
			}
		}
	}
}
