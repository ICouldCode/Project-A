#pragma once
#include <vector>
#include <tuple>
#include "collider_component.h"

class PhysicsSystem
{
public:

	PhysicsSystem() = default;
	~PhysicsSystem() = default;

	std::vector<ColliderComponent*> colliders;
	std::vector<std::tuple<ColliderComponent*, bool>> collisions;

	void addCollider(ColliderComponent* collider)
	{
		colliders.push_back(collider);
		collisions.push_back({collider, false});
	}

	void setColliderState(ColliderComponent* collider, bool isColliding)
	{
		for (auto& [c, state] : collisions)
		{
			if (c == collider)
			{
				state = isColliding;
				return;
			}
		}
	}

	bool getColliderState(ColliderComponent* collider)
	{
		for (auto& [c, state] : collisions)
		{
			if (c == collider)
			{
				return state;
			}
		}
	}

	void Update();

};