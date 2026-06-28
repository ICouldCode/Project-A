#include "player.h"
#include "wall.h"
#include "enemy.h"
#include "collider_component.h"
#include "physics_system.h"

int main(void) {

	const int screenWidth = 1920;
	const int screenHeight = 1080;

	float deltaTime = 0.0f;

	InitWindow(screenWidth, screenHeight, "window");
	//SetTargetFPS(60);

	PhysicsSystem physicsSystem;

	Player player;
	ColliderComponent* playerCollider = new ColliderComponent();
	player.AddComponent(playerCollider);
	physicsSystem.addCollider(playerCollider);
	
	Enemy enemy;
	ColliderComponent* enemyCollider = new ColliderComponent();
	enemy.AddComponent(enemyCollider);	
	enemy.position = { 100, 100 };
	physicsSystem.addCollider(enemyCollider);
	
	Wall wall;
	ColliderComponent* wallCollider = new ColliderComponent();
	wall.AddComponent(wallCollider);
	wall.position = { 400, 400 };
	physicsSystem.addCollider(wallCollider);

	while (!WindowShouldClose()) {
		//Update	
		deltaTime = GetFrameTime();
		player.Update(deltaTime);
		enemy.Update(deltaTime);
		wall.Update(deltaTime);
		physicsSystem.Update();

		//Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);

		player.Draw(deltaTime);
		enemy.Draw(deltaTime);
		wall.Draw(deltaTime);

		DrawFPS(10, 10);
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}