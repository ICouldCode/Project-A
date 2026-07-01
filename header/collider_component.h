#pragma once
#include "raylib.h"
#include "component.h"

enum class ColliderType{
    Interaction,
    HitBox,
    Body
};

class ColliderComponent : public Component
{
public:
    ColliderComponent() = default;
    virtual ~ColliderComponent() = default;

    Vector2 offset = { 0, 0 };
    Vector2 scale = {1.0f, 1.0f};

    ColliderType type = ColliderType::Body;

    bool drawHitbox = true;

    bool isSolid = true;
    bool isTrigger = false;

    bool isTriggerd = false;

	bool isCollidingLeft = false;
	bool isCollidingRight = false;
    bool isCollidingUp = false;
    bool isCollidingDown= false;
    
    
    bool isColliding(){
        return isCollidingUp || isCollidingLeft || isCollidingRight || isCollidingDown;
    }

    void Draw(float deltaTime) override;

    Rectangle GetBounds() const;
	Rectangle GetBoundsAt(Vector2 pos) const;
    Rectangle GetCircleBounds(Vector2 pos, float radius) const;

    void OnCollisionStay(ColliderComponent* other) override;
    void OnCollisionEnter(ColliderComponent* other) override;
	void OnCollisionExit() override;

    void OnTriggerStay(ColliderComponent* other) override;
    void OnTriggerEnter(ColliderComponent* other) override;
    void OnTriggerExit() override;

    void DrawCollisionMesh(Rectangle rec, Color Color) const;
};
