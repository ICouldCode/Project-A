#pragma once
#include "raylib.h"
#include "component.h"

class ColliderComponent : public Component
{
public:
    ColliderComponent() = default;
    virtual ~ColliderComponent() = default;

    Vector2 offset = { 0, 0 };

    bool isSolid = true;
    bool isTrigger = false;

	bool isCollidingLeft = false;
	bool isCollidingRight = false;
    bool isCollidingUp = false;
    bool isCollidingDown= false;

    Rectangle GetBounds() const;
	Rectangle GetBoundsAt(Vector2 pos) const;

    void OnCollisionStay(ColliderComponent* other) override;

    void OnCollisionEnter(ColliderComponent* other) override;

	void OnCollisionExit() override;
};
