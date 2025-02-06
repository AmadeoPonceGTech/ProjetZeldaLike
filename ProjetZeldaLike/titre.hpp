#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "exit.hpp"

using namespace std;
using namespace sf;

class Titre : public Menu {
public:

	Titre();

	void draw(RenderWindow& window) override;
};
