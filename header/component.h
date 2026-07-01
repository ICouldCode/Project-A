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
	virtual void Draw(float deltaTime) {};

	virtual void OnCollisionStay(ColliderComponent* other) {};
	virtual void OnCollisionEnter(ColliderComponent* other) {};
	virtual void OnCollisionExit() {};

	virtual void OnTriggerStay(ColliderComponent* other) {};
	virtual void OnTriggerEnter(ColliderComponent* other){};
	virtual void OnTriggerExit() {};
};