#include "Game.h"
#include <SFML/System/Clock.hpp>


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
	


	//PotionDMG pot({ 90,90 });
	Player player(100, 50, 0.35f, Vector2f(0, 0));
	vector<Enemy*> enemyList;
	vector<Enemy*> enemyListTemp;
	enemyList.push_back(new Chaser(100, 1, 0.20f, Vector2f(200, 200)));
	enemyList.push_back(new Patroler(100, 1, 0.2f, Vector2f(500, 400)));
	Boss boss(1000, 10, 0.3f, Vector2f(300, 300));
	BossBullet bullet(5, 5, { 50,50 }, 10);




	Map mapp(window);
	mapp.initall();
	mapp.initM(currentMap);
	mapp.DrawM(player, view, currentMap);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		deltaTime = clock.restart().asMilliseconds();
		window.clear();
		window.setView(view);

		mapp.eDonj(player, view, currentMap);
		mapp.DrawM(player, view, currentMap);


		window.clear();
		player.update(deltaTime, enemyList);


		enemyListTemp.clear();
		for (auto e : enemyList) {
			e->update(deltaTime, player);
			if (!(e->isDead && e->sprite.getColor().a <= 2))
			{
				enemyListTemp.push_back(e);
			}
		}
		enemyList = enemyListTemp;



		mapp.eDonj(player,view,currentMap);
		mapp.DrawM(player, view,currentMap);

		

		player.draw(window, view);
		
		


		for (auto& e : enemyList) {
			e->draw(window, view);
		}
		boss.draw(window, view);
		boss.update(deltaTime, player);
		bullet.draw(window, view);
		bullet.update(deltaTime, player);
	

		
		window.display();
	}
}
