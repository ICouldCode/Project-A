#pragma once
#include "component.h"

class player_move : public Component
{
public:
    player_move();
    ~player_move();

    void Update(float deltaTime) override;
    void Draw(float deltaTime) override;
    void OnCollisionEnter(ColliderComponent* other) override;
	void OnCollisionStay(ColliderComponent* other) override;
	void OnCollisionExit() override;

    void OnTriggerEnter(ColliderComponent* other) override;
    void OnTriggerStay(ColliderComponent* other) override;
    void OnTriggerExit() override;
};