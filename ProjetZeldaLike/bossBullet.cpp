#include "bossBullet.h"


BossBullet::BossBullet(int d, float s, Vector2f p, float o) : Entity(0, d, s, p)
{
    realOrientation = o;
    try {
        if (!texturebullet.loadFromFile("Assets/Boss/chaser.png")) {
            throw std::runtime_error("Erreur de chargement de la texture (chaser.png)");
        }
    }
    catch (const exception& e) {
        cout << "Probleme detecte : " << e.what() << endl;
    }

    spritebullet.setTexture(texturebullet);
    spritebullet.setScale(Vector2f(0.3f, 0.3f));
}

void BossBullet::update(float deltaTime, Player& p)
{
    time += deltaTime;

    Vector2f pPos = Vector2f(p.getPos().x + (p.getSprite().getLocalBounds().width / 2), p.getPos().y + (p.getSprite().getLocalBounds().height / 2));
    float targetAngle = atan2(pPos.y - pos.y, pPos.x - pos.x);

    float angleDiff = targetAngle - realOrientation;

    while (angleDiff > M_PI) angleDiff -= 2 * M_PI;
    while (angleDiff < -M_PI) angleDiff += 2 * M_PI;

    float rotationSpeed = 0.005f * deltaTime * speed;
    realOrientation += std::clamp(angleDiff, -rotationSpeed, rotationSpeed);

    float dx = cos(realOrientation) * speed * deltaTime;
    float dy = sin(realOrientation) * speed * deltaTime;
    pos = Vector2f(pos.x + dx, pos.y + dy);

    if (spritebullet.getGlobalBounds().intersects(p.getSprite().getGlobalBounds()))
    {
        p.setHealth(p.getHealth() - damage);
    }

}


void BossBullet::draw(RenderWindow& window, View& view)
{
	spritebullet.setPosition(pos);
    if (time > 5000)
    {
        spritebullet.setColor(Color(255, 255, 255, 255 - ((time - 5000) / 2000 * 255)));
    }

	window.draw(spritebullet);
}
