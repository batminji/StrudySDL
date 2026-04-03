#include "stdafx.h"
#include "Character.h"
#include "Engine.h"
#include "World.h"
#include "CollisionComponent.h"

ACharacter::ACharacter()
{
}

ACharacter::~ACharacter()
{
}

bool ACharacter::PredictMove(FVector2D InLocation)
{
	for (auto Other : GEngine->GetWorld()->GetAllActorsOfClass())
	{
		if (Other == this)
		{
			continue;
		}
		for (auto OtherComponent : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				/*if (OtherCollision->GetbIsGenerateOverlap() && InLocation.X == Other->GetActorLocation().X && InLocation.Y == Other->GetActorLocation().Y)
				{
					ProcessBeginOverlap(Other);
					return true;
				}*/
				if (OtherCollision->GetbIsGenerateHit() && InLocation.X == Other->GetActorLocation().X && InLocation.Y == Other->GetActorLocation().Y)
				{
					ReceiveHit(Other);
					return false;
				}
			}
		}
	}
	return true;
}
