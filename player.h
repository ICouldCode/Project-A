#pragma once
#include "gameobject.h"

class Player : public GameObject
{
public:
    Player();
    ~Player();

    void OnUpdate(float deltaTime) override;
    void Draw(float deltaTime) const override;

    float speed = 100.0f;
};