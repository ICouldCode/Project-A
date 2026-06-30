#include "physics_system.h"
#include "gameobject.h"


void PhysicsSystem::Update()
{
    for (ColliderComponent* c : colliders)
    {
        c->isCollidingLeft = false;
        c->isCollidingRight = false;
        c->isCollidingUp = false;
        c->isCollidingDown = false;
    }

    for (ColliderComponent* colliderA : colliders)
    {
        Vector2 testX = colliderA->owner->position;
        testX.x = colliderA->owner->nextPosition.x;

        bool blockedX = false;
        for (ColliderComponent* colliderB : colliders)
        {
            if (colliderB == colliderA) continue;
            if (!colliderB->isSolid) continue;

            if (CheckCollisionRecs(colliderA->GetBoundsAt(testX), colliderB->GetBounds()))
            {
                blockedX = true;
                break;
            }
        }
        if (!blockedX)
            colliderA->owner->position.x = colliderA->owner->nextPosition.x;
        Vector2 testY = colliderA->owner->position;
        testY.y = colliderA->owner->nextPosition.y;
        bool blockedY = false;
        for (ColliderComponent* colliderB : colliders)
        {
            if (colliderB == colliderA) continue;
            if (!colliderB->isSolid) continue;

            if (CheckCollisionRecs(colliderA->GetBoundsAt(testY), colliderB->GetBounds()))
            {
                blockedY = true;
                break;
            }
        }
        if (!blockedY)
            colliderA->owner->position.y = colliderA->owner->nextPosition.y;
        
        bool state = getColliderState(colliderA);
        if (blockedX || blockedY) {
            if (state == false) {
				setColliderState(colliderA, true);
				for (ColliderComponent* colliderB : colliders)
				{
					if (colliderB == colliderA) continue;
					if (!colliderB->isSolid) continue;
					if (CheckCollisionRecs(colliderA->GetBounds(), colliderB->GetBounds()))
					{
						colliderA->OnCollisionEnter(colliderB);
						colliderB->OnCollisionEnter(colliderA);
					}
				}
            }
            else {
                for (ColliderComponent* colliderB : colliders)
                {
                    if (colliderB == colliderA) continue;
                    if (!colliderB->isSolid) continue;
                    if (CheckCollisionRecs(colliderA->GetBounds(), colliderB->GetBounds()))
                    {
                        colliderA->OnCollisionStay(colliderB);
                        colliderB->OnCollisionStay(colliderA);
                    }
                }
            }
        }
        if (state == true && !blockedX && !blockedY) {
            setColliderState(colliderA, false);
			colliderA->OnCollisionExit();
        }
        colliderA->owner->nextPosition = colliderA->owner->position;
    }
}