#include "bossBullet.h"


BossBullet::BossBullet(int d, float s, Vector2f p, float o) : Entity(0, d, s, p), realOrientation(o)
{
	realOrientation = o;
    try {
        if (!autoAimTexture.loadFromFile("Assets/Boss/chaser.png")) {
            throw std::runtime_error("Erreur de chargement de la texture (player walk)");
        }
    }
    catch (const exception& e) {
        cout << "Probleme detecte : " << e.what() << endl;
    }

    autoAimSprite.setTexture(autoAimTexture);
    autoAimSprite.setScale(Vector2f(1, 1));
}

void BossBullet::update(float deltaTime, Player& p)
{
    time += deltaTime;

    Vector2f pPos = p.getPos();
    float targetAngle = atan2(pPos.y - pos.y, pPos.x - pos.x);

    float angleDiff = targetAngle - realOrientation;

    while (angleDiff > M_PI) angleDiff -= 2 * M_PI;
    while (angleDiff < -M_PI) angleDiff += 2 * M_PI;

    float rotationSpeed = 0.005f * deltaTime * speed;
    realOrientation += std::clamp(angleDiff, -rotationSpeed, rotationSpeed);

    float dx = cos(realOrientation) * speed * deltaTime;
    float dy = sin(realOrientation) * speed * deltaTime;
    pos = Vector2f(pos.x + dx, pos.y + dy);
}


void BossBullet::draw(RenderWindow& window, View& view)
{
	autoAimSprite.setPosition(pos);
    if (time > 5000)
    {
        autoAimSprite.setColor(Color(255, 255, 255, 255 - ((time - 5000) / 2000 * 255)));
    }

	window.draw(autoAimSprite);
}
