#pragma once

class GameObject;

class Component
{
public:
	Component() = default;

	GameObject* owner = nullptr;

	virtual ~Component() = default;
	virtual void Update(float deltaTime) {};
};