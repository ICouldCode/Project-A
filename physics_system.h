#pragma once
#include <vector>
#include "collider_component.h"

class PhysicsSystem
{
public:

	PhysicsSystem() = default;
	~PhysicsSystem() = default;

	std::vector<ColliderComponent*> colliders;


	void addCollider(ColliderComponent* collider)
	{
		colliders.push_back(collider);
	}

	void Update();

};