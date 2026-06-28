#include "wall.h"


Wall::Wall() {
}

Wall::~Wall() {
}

void Wall::OnUpdate(float deltaTime) {

}

void Wall::Draw(float deltaTime) const {
	DrawRectangleRec(
        Rectangle{ nextPosition.x, nextPosition.y, width, height },
        GRAY
    );
}