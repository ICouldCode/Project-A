#include "enemy.h"

Enemy::Enemy(){
}

Enemy::~Enemy() {
}

void Enemy::OnUpdate(float deltaTime) {
	//position.x += speed * deltaTime; // Move right at a constant speed
}

void Enemy::Draw(float deltaTime) const {
	DrawRectangleRec(
		Rectangle{ nextPosition.x, nextPosition.y, width, height },
		RED
	);
}
