#pragma once

class GameObject;
class ColliderComponent;

class Component
{
public:
	Component() = default;

	GameObject* owner = nullptr;

	virtual ~Component() = default;
	virtual void Update(float deltaTime) {};

	virtual void OnCollisionStay(ColliderComponent* other) {}

	virtual void OnCollisionEnter(ColliderComponent* other) {}

	virtual void OnCollisionExit() {}
};