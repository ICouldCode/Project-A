#pragma once
#include "gameobject.h"

class Wall : public GameObject
{
public:
	Wall();
	~Wall();

	void OnUpdate(float deltaTime) override;
	void Draw(float deltaTime) const override;
};