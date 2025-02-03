#include "Game.h"
#include <SFML/System/Clock.hpp>

#include "enemyPatrol.h"
#include "enemyChaser.h"
#include "potionDMG.h"
#include "potion.h"
#include "potionPOI.h"


Game::Game()
{
	view.setSize(Vector2f(1920, 1080));
	view.zoom(0.5f);
	window.setView(view);
}

void Game::run()
{
	RenderWindow window = RenderWindow(VideoMode(1920, 1080), "zelda");
	window.setFramerateLimit(60);

	Player player(100, 5, 0.35f, Vector2f(0, 0));
	vector<Enemy*> enemyList;
	enemyList.push_back(new Chaser(100, 1, 0.20f, Vector2f(200, 200)));
	PotionPOI pot({ 500,250 });

	Map mapp(window);
	//mapp.eDonj(player, view, currentMap);
	mapp.initall();
	mapp.initM(currentMap);
	mapp.DrawM(player,view);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		deltaTime = clock.restart().asMilliseconds();

		window.clear();

		player.update(deltaTime, enemyList);

		for (auto e : enemyList) {
			e->update(deltaTime, player);
		}

		window.setView(view);
	
		mapp.eDonj(player,view,currentMap);
		mapp.DrawM(player, view);
		mapp.tpTxt(player);
		mapp.pnjTxt(player);
		mapp.coliM(player);

		pot.draw(window);
		pot.itemEffect(player);
		player.checkPowerup();



		player.draw(window, view);

		for (auto e : enemyList) {
			e->draw(window, view);
		}
		
		window.setView(view);
		window.display();
	}
}
