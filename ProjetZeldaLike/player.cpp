#include "player.h"
#include "Boss.h"
using namespace sf;
using namespace std;

Player::Player(int health, int dmg, float s, Vector2f p) : Entity(health, dmg, s, p) 
{
    try {
        if (!textureWalk.loadFromFile("Assets/GladiatorBlue/SeparateAnim/Walk.png")) {
            throw std::runtime_error("Erreur de chargement de la texture (player walk)");
        }
        if (!textureIdle.loadFromFile("Assets/GladiatorBlue/SeparateAnim/Idle.png")) {
            throw std::runtime_error("Erreur de chargement de la texture (player idle)");
        }
        if (!textureAttack.loadFromFile("Assets/GladiatorBlue/SeparateAnim/Attack.png")) {
            throw std::runtime_error("Erreur de chargement de la texture (player attack)");
        }
        if (!weapon1.loadFromFile("Assets/Lance/SpriteInHand.png")) {
            throw std::runtime_error("Erreur de chargement de la texture (player lance)");
        }
    }
    catch (const exception& e){
        cout << "Probleme detecte : " << e.what() << endl;
    }

    sprite.setTexture(textureIdle);

    weaponSprite.setTexture(weapon1);
    weaponSprite.setScale(Vector2f(3, 3));
}

void Player::update(float deltaTime, vector<Enemy*> p, Boss& boss)
{
    move(deltaTime);
    attack(deltaTime, p, boss);
    animationUpdate(deltaTime);
}



void Player::animationUpdate(float deltaTime) 
{
    timer += deltaTime;

    if (Keyboard::isKeyPressed(Keyboard::Z) ||
        Keyboard::isKeyPressed(Keyboard::Q) ||
        Keyboard::isKeyPressed(Keyboard::S) ||
        Keyboard::isKeyPressed(Keyboard::D)) 
    { isMoving = true; }
    else { isMoving = false; }

    if (isMoving) { animState = "Walk"; }
    else { animState = "Idle"; }
    if (Mouse::isButtonPressed(Mouse::Left) && timeSinceLastAttack < attackDuration)
    {
        animState = "Attack";
        attackstate = true;
    }
    else
    {
        attackstate =false;
    }

    if (animState == "Idle")
    {
        frameCount = 1;
        sprite.setTexture(textureIdle);
    }
    else if (animState == "Walk")
    {
        frameCount = 4;
        sprite.setTexture(textureWalk);
    }
    else if (animState == "Attack")
    {
        frameCount = 1;
        sprite.setTexture(textureAttack);
    }

    if (animState != animStateBackup)
    {
        animStateBackup = animState;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, 0, frameWidth, frameHeight));
    }

    if (timer > frameDuration)
    {
        timer = 0;
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(IntRect(((getOrientation() + 90) / 90 % 4) * frameHeight, currentFrame * frameWidth, frameWidth, frameHeight));
    }
}

bool isGoingDiagonal()
{
    int count = 0;
    if (Keyboard::isKeyPressed(sf::Keyboard::Z)) { count += 1; }
    if (Keyboard::isKeyPressed(sf::Keyboard::S)) { count += 1; }
    if (Keyboard::isKeyPressed(sf::Keyboard::D)) { count += 1; }
    if (Keyboard::isKeyPressed(sf::Keyboard::Q)) { count += 1; }

    return count == 2;
}

void Player::move(float deltaTime)
{
    if (canMove) {
        bool isDiagonal = isGoingDiagonal();
        float isDiagonalMultiplier = 1;

        if (isDiagonal)
        {
            isDiagonalMultiplier = 1 / sqrt(2);
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            setPos(Vector2f(getPos().x, getPos().y - getSpeed() * deltaTime * isDiagonalMultiplier));
            setOrientation(270);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            setPos(Vector2f(getPos().x, getPos().y + getSpeed() * deltaTime * isDiagonalMultiplier));
            setOrientation(90);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            setPos(Vector2f(getPos().x - getSpeed() * deltaTime * isDiagonalMultiplier, getPos().y));
            setOrientation(180);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            setPos(Vector2f(getPos().x + getSpeed() * deltaTime * isDiagonalMultiplier, getPos().y));
            setOrientation(0);
        }
    }
}

bool isInside(Vector2f edges[4], Vector2f posPoint) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        Vector2f a = edges[i];
        Vector2f b = edges[(i + 1) % 4];

        if ((a.y > posPoint.y) != (b.y > posPoint.y)) {
            float intersectX = a.x + (b.x - a.x) * (posPoint.y - a.y) / (b.y - a.y);

            if (posPoint.x < intersectX) {
                count++;
            }
        }
    }
    return count % 2 == 1;
}

void Player::attack(float deltaTime, vector<Enemy*> ennemy, Boss& boss)
{
    timeSinceLastAttack += deltaTime;
    if (timeSinceLastAttack > attackDuration)
    {
        canMove = true;

        if (timeSinceLastAttack > attackDuration + attackDelay) {
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                timeSinceLastAttack = 0;
                canMove = false;

                float radO = getOrientation() * (M_PI / 180);
                Vector2f pPos = getPos();
                Vector2f attackHitBox[4] =
                {
                    Vector2f(pPos.x + (sin(radO) * attackSize), pPos.y - (cos(radO) * attackSize)),
                    Vector2f(pPos.x - (sin(radO) * attackSize), pPos.y + (cos(radO) * attackSize)),
                    Vector2f((pPos.x + (cos(radO) * attackRange)) - (sin(radO) * attackSize), (pPos.y + (sin(radO) * attackRange)) + (cos(radO) * attackSize)),
                    Vector2f((pPos.x + (cos(radO) * attackRange)) + (sin(radO) * attackSize), (pPos.y + (sin(radO) * attackRange)) - (cos(radO) * attackSize))
                };

                for (auto e : ennemy)
                {
                    if (isInside(attackHitBox, e->getPos()))
                    {
                        e->takeHit(getDamage());
                        e->giveStunt(100.f);
                    }
                }
                if (isInside(attackHitBox, boss.getSprite().getPosition()))
                {
                    boss.BossHit(damage);
                    cout << damage;
                }
            }
        }
    }
}

void Player::usePowerUp()
{
    if (buff)
    {
        cout << getDamage() << endl;
        setDamage(getDamage() + 20);
        sprite.setColor(Color::Blue);
        cout << getDamage();
    }
}


void Player::draw(RenderWindow& window, View& view)
{
    sprite.setPosition(getPos());
    weaponSprite.setPosition(Vector2f(getPos().x + 8*sprite.getScale().x, getPos().y + 8 * sprite.getScale().x));

    weaponSprite.setRotation(orientation - 90);
    setWeaponOrientation();

    view.setCenter(getPos());
    window.draw(sprite);
    if (animState == "Attack") {
        window.draw(weaponSprite);
    }
}

Sprite& Player::getSprite()
{
    return sprite;
}

Sprite& Player::getweaponSprite()
{
    return weaponSprite;
}

void Player::setWeaponOrientation()
{
    if (orientation == 0 || orientation == 90)
    {
        weaponSprite.setOrigin(Vector2f(6, -8));
    }
    if (orientation == 180 || orientation == 270)
    {
        weaponSprite.setOrigin(Vector2f(-1, -8));
    }
}

