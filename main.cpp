#include "collider_component.h"
#include "physics_system.h"
#include "player_move.h"
#include "gameobject.h"

#include <algorithm>

int main(void) {

	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	float deltaTime = 0.0f;

	InitWindow(screenWidth, screenHeight, "window");
	SetTargetFPS(60);

	std::vector<GameObject*> gameObjects;

	PhysicsSystem physicsSystem;

	GameObject player;
	player_move* moveComponent = new player_move();
	player.AddComponent(moveComponent);
	player.color = BLUE;
	ColliderComponent* playerCollider = new ColliderComponent();
	player.AddComponent(playerCollider);
	physicsSystem.addCollider(playerCollider);
	player.layer = 1;
	player.width = 128.0f;
	player.height = 128.0f;
	
	GameObject npc;
	npc.color = GREEN;
	ColliderComponent* enemyCollider = new ColliderComponent();
	npc.AddComponent(enemyCollider);	
	enemyCollider->isSolid = true;
	npc.position = { 200, 200 };
	physicsSystem.addCollider(enemyCollider);
	npc.tag = Tag::Interact;
	npc.name = "NPC";
	npc.layer = 1;
	npc.width = 128.0f;
	npc.height = 128.0f;
	
	GameObject floor;
	ColliderComponent* wallCollider = new ColliderComponent();
	wallCollider->isSolid = false;
	floor.AddComponent(wallCollider);
	physicsSystem.addCollider(wallCollider);
	floor.texture = LoadTexture("images.png");
	floor.width = 1600.0f;
	floor.height = 1600.0f;
	floor.position = { 0 - (floor.width / 2),0 - (floor.height / 2) };

	gameObjects.push_back(&player);
	gameObjects.push_back(&npc);
	gameObjects.push_back(&floor);


	std::sort(gameObjects.begin(), gameObjects.end(), [](GameObject* a, GameObject* b) {
		return a->layer < b->layer;
		});

	Camera2D camera = { 0 };
	camera.target = player.position;
	camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = camera.zoom = GetScreenWidth() / 1920.0f;

	while (!WindowShouldClose()) {

		//Handlers
		if (IsKeyPressed(KEY_F11))
		{
			ToggleFullscreen();
			if (!IsWindowFullscreen()) {
				SetWindowSize(1280, 720);
			}

			camera.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
			camera.zoom = GetScreenWidth() / 1920.0f; // scale relative to your base resolution
		}

		//Update	
		deltaTime = GetFrameTime();
		for (GameObject* object : gameObjects)
		{
			object->Update(deltaTime);
		}
		physicsSystem.Update();
		//camera.target = player.position;
		
		//Draw
		BeginDrawing();
		ClearBackground(BLACK);
		BeginMode2D(camera);
		for (GameObject* object : gameObjects)
		{
			object->Draw(deltaTime);
		}

		EndMode2D();
		DrawFPS(10, 10);
		EndDrawing();
	}
	

	for (GameObject* object : gameObjects)
	{
		object->Cleanup();
	}
	CloseWindow();
	return 0;
}