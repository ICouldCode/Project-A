#include "collider_component.h"
#include "GameObject.h" 


Rectangle ColliderComponent::GetBounds() const
{
    return Rectangle{
               owner->nextPosition.x + offset.x,
               owner->nextPosition.y + offset.y,
               owner->width,
               owner->height,
    };
}

Rectangle ColliderComponent::GetBoundsAt(Vector2 pos) const
{
    return {
        pos.x + offset.x,
        pos.y + offset.y,
        owner->width,
        owner->height,
    };
}

void ColliderComponent::OnCollisionStay(ColliderComponent* other) 
{
    for (Component* c : owner->GetComponents())
    {
        if (c == this) continue;
        c->OnCollisionStay(other);
    }
}

void ColliderComponent::OnCollisionEnter(ColliderComponent* other)
{
    for (Component* c : owner->GetComponents())
    {
        if (c == this) continue;
        c->OnCollisionEnter(other);
    }
}

void ColliderComponent::OnCollisionExit()
{
	for (Component* c : owner->GetComponents())
	{
		if (c == this) continue;
		c->OnCollisionExit();
	}
}