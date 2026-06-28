#pragma once
#include "gameobject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	void OnUpdate(float deltaTime) override;
	void Draw(float deltaTime) const override;
	float speed = 100.0f;
};