#include "bossBullet.h"


BossBullet::BossBullet(int h, int d, float s, Vector2f p, float o) : Entity(h, d, s, p)
{
	realOrientation = o;
}

void BossBullet::update(float deltaTime, Player& p)
{
    time += deltaTime;

    Vector2f pPos = Vector2f(p.getPos().x + (p.getSprite().getLocalBounds().width/2), p.getPos().y + (p.getSprite().getLocalBounds().height / 2));
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
	CircleShape circle(10);
	circle.setPosition(pos);
    if (time > 5000)
    {
        circle.setFillColor(Color(255, 255, 255, 255 - ((time - 5000) / 2000 * 255)));
    }

	window.draw(circle);
}
