#include "coin.h"

Coin::Coin(Vector2f p) : ItemEntity(p)
{
    try {
        if (!texture.loadFromFile("Assets/coin.png")) {
            throw std::runtime_error("Erreur de chargement de la texture (coin)");
        }
    }
    catch (const exception& e) {
        cout << "Probleme detecte : " << e.what() << endl;
    }

    sprite.setTexture(texture);
    sprite.setScale(Vector2f(4, 4));
}

void Coin::update(float deltaTime)
{
    timeSinceLastAnimationUpdate += deltaTime;
    if (timeSinceLastAnimationUpdate > 70) {
        if (animationStep == 6 && timeSinceLastAnimationUpdate < 2000)
        {
            return;
        }
        animationStep = (animationStep + 1) % 7;
        timeSinceLastAnimationUpdate = 0;
    }
    sprite.setTextureRect(IntRect(Vector2i(0, 16 * animationStep), Vector2i(16, 16)));
}

void Coin::draw(RenderWindow& window)
{
    window.draw(sprite);
}

void Coin::itmget()
{
}

void Coin::itemEffect(Player& player)
{
    
}