#pragma once
#include "raylib.h"
#include "component.h"
#include <vector>
#include <tuple>

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;

	void AddComponent(Component* component) {
        component->owner = this;
        components.push_back(component);
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
        for (auto& c : components)
            c->Update(dt);

		nextPosition = position;

        OnUpdate(dt);
    }

    virtual void OnUpdate(float deltaTime) {};
    virtual void Draw(float deltaTime) const {};



    Vector2 position = { 0,0 };
	Vector2 nextPosition = { 0,0 };

    float rotation = 0;

    float width = 32;
    float height = 32;
	float speed = 200.0f;

private:
    std::vector<Component*> components;
};