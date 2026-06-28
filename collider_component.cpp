#include "collider_component.h"
#include "GameObject.h" 


Rectangle ColliderComponent::GetBounds() const
{
    return Rectangle{
               owner->nextPosition.x + offset.x,
               owner->nextPosition.y + offset.y,
               size.x,
               size.y
    };
}

Rectangle ColliderComponent::GetBoundsAt(Vector2 pos) const
{
    return {
        pos.x + offset.x,
        pos.y + offset.y,
        size.x,
        size.y
    };
}