#include "player.h"
#include "collider_component.h"

Player::Player() : GameObject() {
}

Player::~Player(){
}

void Player::OnUpdate(float deltaTime) {

    Vector2 moveDirection = { 0, 0 };

    if (IsKeyDown(KEY_W)) moveDirection.y = -1;
    else if (IsKeyDown(KEY_S)) moveDirection.y = 1;
    else if (IsKeyDown(KEY_A)) moveDirection.x = -1;
    else if (IsKeyDown(KEY_D)) moveDirection.x = 1;

    nextPosition = position;
    nextPosition.x += moveDirection.x * speed * deltaTime;
    nextPosition.y += moveDirection.y * speed * deltaTime;
}

void Player::Draw(float deltaTime) const {
    DrawRectangleRec(
        Rectangle{ position.x, position.y, width, height },
        BLACK
    );
}