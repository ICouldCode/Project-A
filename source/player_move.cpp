#include "player_move.h"
#include "gameobject.h"
#include "collider_component.h"
#include <iostream>

void player_move::Update(float deltaTime)
{
    Vector2 moveDirection = { 0, 0 };

    ColliderComponent* colI = owner->GetCollider(ColliderType::Interaction);
 
    if (IsKeyDown(KEY_W)) {
        moveDirection.y = -1;

        colI->offset.y = -owner->height * 2;
        colI->offset.x = -owner->width / 4;
    }
    else if (IsKeyDown(KEY_S)) {
        moveDirection.y = 1;

        colI->offset.y = owner->height;
        colI->offset.x = -owner->width / 4;
    }
    else if (IsKeyDown(KEY_A)){ 
        moveDirection.x = -1;

        colI->offset.x = -owner->width * 1.5f;
        colI->offset.y = -owner->height / 2;
        
    }
    else if (IsKeyDown(KEY_D)){
        moveDirection.x = 1;

        colI->offset.x = owner->width;
        colI->offset.y = -owner->height / 2;
        
    }

    owner->nextPosition = owner->position;
    owner->nextPosition.x += moveDirection.x * owner->speed * deltaTime;
    owner->nextPosition.y += moveDirection.y * owner->speed * deltaTime;

}

void player_move::Draw(float deltaTime) {
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

void player_move::OnTriggerEnter(ColliderComponent* other)
{
    std::cout << "Trigger Enter" << std::endl;
}

void player_move::OnTriggerStay(ColliderComponent* other)
{
    if(owner->GetCollider(ColliderType::Interaction) && other->type == ColliderType::Interaction){
        if(owner != other->owner){
            if(owner->GetCollider(ColliderType::Interaction) != other->owner->GetCollider(ColliderType::Interaction)){
                if(IsKeyPressed(KEY_E)){
                    std::cout << "Interaction Hit" + other->owner->name << std::endl;
                }
            }
        }
    }
}
void player_move::OnTriggerExit()
{
    std::cout << "Trigger Exit" << std::endl;
}

player_move::player_move() {}
player_move::~player_move() {}