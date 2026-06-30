#pragma once
#include "component.h"

class player_move : public Component
{
public:
    player_move();
    ~player_move();

    void Update(float deltaTime) override;
    void OnCollisionEnter(ColliderComponent* other) override;
	void OnCollisionStay(ColliderComponent* other) override;
	void OnCollisionExit() override;
};