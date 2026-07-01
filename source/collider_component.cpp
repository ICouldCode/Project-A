#include "collider_component.h"
#include "gameobject.h"


void ColliderComponent::Draw(float deltaTime){
    if(drawHitbox){
        DrawCollisionMesh(GetBounds(), RED);
    }
}

Rectangle ColliderComponent::GetBounds() const
{
    return Rectangle{
               owner->nextPosition.x + offset.x,
               owner->nextPosition.y + offset.y,
               owner->width * scale.x,
               owner->height * scale.y,
    };
}

Rectangle ColliderComponent::GetBoundsAt(Vector2 pos) const
{
    return {
        pos.x + offset.x,
        pos.y + offset.y,
        owner->width * scale.x,
        owner->height * scale.y,
    };
}

Rectangle ColliderComponent::GetCircleBounds(Vector2 pos, float radius) const{
    
    return{
        (pos.x + (owner->width / 2.0f)) - radius, // x
        (pos.y + (owner->height / 2.0f)) - radius, // y
        radius * 2.0f * scale.x, // width
        radius * 2.0f * scale.y // height
    };
}

void ColliderComponent::DrawCollisionMesh(Rectangle rec, Color color) const{

    DrawRectangleLines(rec.x, rec.y, rec.width, rec.height, color);
}

void ColliderComponent::OnCollisionStay(ColliderComponent* other) 
{
    for (Component* c : owner->GetComponents())
    {
        if (dynamic_cast<ColliderComponent*>(c) != nullptr) continue;
        c->OnCollisionStay(other);
    }
}
void ColliderComponent::OnCollisionEnter(ColliderComponent* other)
{
    for (Component* c : owner->GetComponents())
    {
        if (dynamic_cast<ColliderComponent*>(c) != nullptr) continue;
        c->OnCollisionEnter(other);
    }
}
void ColliderComponent::OnCollisionExit()
{
	for (Component* c : owner->GetComponents())
	{
		if (dynamic_cast<ColliderComponent*>(c) != nullptr) continue;
		c->OnCollisionExit();
	}
}

void ColliderComponent::OnTriggerStay(ColliderComponent* other)
{
    for (Component* c : owner->GetComponents())
    {
        if (dynamic_cast<ColliderComponent*>(c) != nullptr) continue;
        c->OnTriggerStay(other);
    }
}

void ColliderComponent::OnTriggerEnter(ColliderComponent* other)
{
    for (Component* c : owner->GetComponents())
        {
            if (dynamic_cast<ColliderComponent*>(c) != nullptr) continue;
            c->OnTriggerEnter(other);
        }
}

void ColliderComponent::OnTriggerExit()
{
    for (Component* c : owner->GetComponents())
	{
		if (dynamic_cast<ColliderComponent*>(c) != nullptr) continue;
		c->OnTriggerExit();
	}
}