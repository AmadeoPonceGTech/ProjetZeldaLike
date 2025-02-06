#include "back.hpp"

Back::Back() {
	texture.loadFromFile("Assets/Menu/Back.png");
	sprite.setTexture(texture);
	sprite.setPosition(10, 800);

}

void Back::draw(RenderWindow& window) {
	window.draw(sprite);
}
