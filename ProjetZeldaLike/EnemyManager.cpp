#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	/*enemyList.push_back(new Chaser(100, 1, 0.20f, Vector2f(200, 200)));
	enemyList.push_back(new Patroler(100, 1, 0.2f, Vector2f(500, 400), 1));*/
}

void EnemyManager::update(float deltaTime, Player& p)
{
	enemyListTemp.clear();
	for (auto e : enemyList) {
		e->update(deltaTime, p);
		if (!(e->isDead && e->sprite.getColor().a <= 2))
		{
			enemyListTemp.push_back(e);
		}
	}
	enemyList = enemyListTemp;

	//check player color

	for (auto e : enemyList)
	{
		if (e->isPlayerRed)
		{
			p.getSprite().setColor(Color::Red);
			return;
		}
		p.getSprite().setColor(Color::White);
	}
}

void EnemyManager::draw(RenderWindow& window, View& view)
{
	for (auto& e : enemyList) {
		e->draw(window, view);
	}
}

vector<Enemy*>& EnemyManager::getEnemyList()
{
	return enemyList;
}
