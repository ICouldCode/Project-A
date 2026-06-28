#pragma once
#include <iostream>
#include "raylib.h"
#include "component.h"

class ColliderComponent : public Component
{
public:
    ColliderComponent() = default;
    virtual ~ColliderComponent() = default;

    Vector2 offset = { 0, 0 };
    Vector2 size = { 32, 32 };

    bool isSolid = true;
    bool isTrigger = false;

	bool isCollidingLeft = false;
	bool isCollidingRight = false;
    bool isCollidingUp = false;
    bool isCollidingDown= false;

    Rectangle GetBounds() const;
	Rectangle GetBoundsAt(Vector2 pos) const;

    void OnCollisionStay(ColliderComponent* other)
    {
        std::cout << "Collision Enter with another collider!" << std::endl;
    }
};
