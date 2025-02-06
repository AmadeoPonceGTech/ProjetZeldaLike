#pragma once
#include "enemyChaser.h"
#include "enemyPatrol.h"

class EnemyManager
{
private:
	vector<Enemy*> enemyList;
	vector<Enemy*> enemyListTemp;

public:
	EnemyManager();

	void update(float deltaTime, Player& p);
	void draw(RenderWindow& window, View& view);

	vector<Enemy*>& getEnemyList();
};