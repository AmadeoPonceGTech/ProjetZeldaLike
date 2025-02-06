#include "MenuGameOver.hpp"

GameOver::GameOver() {
	texture.loadFromFile("Assets/GameOver/Reset.png");
	sprite.setTexture(texture);
	sprite.setPosition(460, 450);
}


void GameOver::draw(RenderWindow& window) {
	window.draw(sprite);

}
