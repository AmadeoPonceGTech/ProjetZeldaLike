#include <SFML/Graphics.hpp>
#include <iostream>



using namespace std;
using namespace sf;

class Menu {
public:



	Texture texture;
	Sprite sprite;

	Font font;
	Text text;



	virtual void draw(RenderWindow& window) = 0;
};
