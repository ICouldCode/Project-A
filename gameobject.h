#pragma once
#include "raylib.h"
#include "component.h"
#include <vector>
#include <tuple>
#include <string>

enum class Tag
{
	Interact,
    None
};

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;

	Tag tag = Tag::None;

	void AddComponent(Component* component) {
        component->owner = this;
        components.push_back(component);
	}

	std::vector<Component*> GetComponents() const {
		return components;
	}

    template<typename T>
    T* GetComponent()
    {
        for (Component* component : components)
        {
            if (T* result = dynamic_cast<T*>(component))
            {
                return result;
            }
        }

        return nullptr;
    }

    void Update(float dt)
    {
        nextPosition = position;

        for (auto& c : components)
            c->Update(dt);

        OnUpdate(dt);
    }

    virtual void OnUpdate(float deltaTime) {};
    virtual void Draw(float deltaTime) const 
    {
        if (texture.id > 0)
            DrawTexturePro(
                texture,
                Rectangle{ 0, 0, (float)texture.width, (float)texture.height }, // source (full texture)
                Rectangle{ position.x, position.y, width, height },              // dest (your object size)
                Vector2{ 0, 0 },                                                  // origin
                rotation,
                color
            );
		else
			DrawRectangle(position.x,position.y, width, height, color);
    };

	virtual void Cleanup() {
		for (auto& c : components)
			delete c;
		components.clear();
		UnloadTexture(texture);
	}

    Texture2D texture = {0};

    Vector2 position = { 0,0 };
	Vector2 nextPosition = { 0,0 };

    Color color = GRAY;

    float rotation = 0;

    float width = 32;
    float height = 32;
	float speed = 200.0f;

	std::string name = "GameObject";
	int layer = 0;
private:
    std::vector<Component*> components;
};