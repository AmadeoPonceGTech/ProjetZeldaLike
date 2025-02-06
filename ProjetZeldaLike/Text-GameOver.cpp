#include "Text-GameOver.hpp"

Text_GameOver::Text_GameOver() {
	font.loadFromFile("Police d'ecriture/GameOver/Hestrial.otf");
	text.setFont(font);
	text.setString("Game Over");
	text.setCharacterSize(80);
	text.setFillColor(Color::Red);
	text.setPosition(350, 50);
}


void Text_GameOver::draw(RenderWindow& window) {
	window.draw(text);
}
