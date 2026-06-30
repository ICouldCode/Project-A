#include "player_move.h"
#include "gameobject.h"
#include "collider_component.h"
#include <iostream>

void player_move::Update(float deltaTime)
{
    Vector2 moveDirection = { 0, 0 };

    if (IsKeyDown(KEY_W)) moveDirection.y = -1;
    else if (IsKeyDown(KEY_S)) moveDirection.y = 1;
    else if (IsKeyDown(KEY_A)) moveDirection.x = -1;
    else if (IsKeyDown(KEY_D)) moveDirection.x = 1;

    owner->nextPosition = owner->position;
    owner->nextPosition.x += moveDirection.x * owner->speed * deltaTime;
    owner->nextPosition.y += moveDirection.y * owner->speed * deltaTime;

    
}

void player_move::OnCollisionEnter(ColliderComponent* other)
{
}

void player_move::OnCollisionStay(ColliderComponent* other)
{
}

void player_move::OnCollisionExit()
{
}

player_move::player_move() {}
player_move::~player_move() {}