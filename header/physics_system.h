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
	std::vector<std::tuple<ColliderComponent*, bool>> triggers;

	void addCollider(ColliderComponent* collider)
	{
		colliders.push_back(collider);
		if(!collider->isTrigger) collisions.push_back({collider, false});
		else triggers.push_back({collider, false});
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

	void setTriggerState(ColliderComponent* trigger, bool isColliding){
		for (auto& [c, state] : triggers){
			if (c==trigger){
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

		return false;
	}

	bool getTriggerState(ColliderComponent* collider){
		for (auto& [c, state] : triggers){
			if (c == collider){
				return state;
			}
		}

		return false;
	}

	void Update();

};
