#include "titre.hpp"

Titre::Titre() {
	font.loadFromFile("Police d'ecriture/Menu/Hestrial.ttf");
	text.setFont(font);
	text.setString("Evil Pingouin");
	text.setCharacterSize(80);
	text.setFillColor(Color::Cyan);
	text.setPosition(620, 50);
}


void Titre::draw(RenderWindow& window) {
	window.draw(text);
}
