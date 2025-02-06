#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "MenuGameOver.hpp"

using namespace std;
using namespace sf;

class Text_GameOver : public GameOver {
public:

	Text_GameOver();

	void draw(RenderWindow& window) override;
};
