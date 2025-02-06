#include "Start.hpp"


Start::Start() {
	texture.loadFromFile("Assets/Menu/Play.png");
	sprite.setTexture(texture);
	sprite.setPosition(800, 300);
}

void Start::draw(RenderWindow& window) {
	window.draw(sprite);
}



