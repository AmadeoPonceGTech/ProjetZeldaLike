#include "exit.hpp"

Exit::Exit() {
	texture.loadFromFile("Assets/Menu/Exit.png");
	sprite.setTexture(texture);
	sprite.setPosition(1700, 850);
}

void Exit::draw(RenderWindow& window) {
	window.draw(sprite);
}
