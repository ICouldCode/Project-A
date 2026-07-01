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
	player.name = "Player";
	ColliderComponent* interactCollider = new ColliderComponent();
	interactCollider->isSolid = false;
	interactCollider->isTrigger = true;
	interactCollider->offset = {-player.width / 2, -player.height / 2};
	interactCollider->type = ColliderType::Interaction;
	
	interactCollider->scale = {2.0f, 2.0f};
	player.AddComponent(interactCollider);
	physicsSystem.addCollider(interactCollider);
	
	GameObject npc;
	npc.color = GREEN;
	npc.position = { 200, 200 };
	npc.width = 128.0f;
	npc.height = 128.0f;
	ColliderComponent* npcCollider = new ColliderComponent();
	npc.AddComponent(npcCollider);	
	ColliderComponent* npc_interactCollider = new ColliderComponent();
	npc_interactCollider->scale = {2.0f, 2.0f};
	npc_interactCollider->isSolid = false;
	npc_interactCollider->isTrigger = true;
	npc_interactCollider->offset = {-npc.width / 2, -npc.height / 2};
	npc_interactCollider->type = ColliderType::Interaction;
	npcCollider->isSolid = true;
	npc.AddComponent(npc_interactCollider);
	physicsSystem.addCollider(npcCollider);
	physicsSystem.addCollider(npc_interactCollider);
	npc.tag = Tag::NPC;
	npc.name = "NPC";
	npc.layer = 1;

	gameObjects.push_back(&player);
	gameObjects.push_back(&npc);

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

		for (GameObject* obj : gameObjects){
			obj->DrawComponents(deltaTime);
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
