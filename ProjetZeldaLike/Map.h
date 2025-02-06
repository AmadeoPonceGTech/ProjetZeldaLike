#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include<fstream>
#include<sstream>
#include "Player.h"
#include<SFML/Audio.hpp>
#include "Boss.h"
#include "potionDMG.h"
#include "enemy.h"
#include "EnemyManager.h"

#include <chrono>

using namespace std;
using namespace sf;



class Map {
private:
	bool cMap;
public:


	Map(RenderWindow& w);
	bool Keyrecup, iPNJ, isDialogueActive = false;
	Clock clock;
	float deltaTime = clock.restart().asMicroseconds();
	void initTxt();
	void initSprt();
	void initM(string);
	void initF();
	void initT();
	void DrawM(Player&, View& v, string& currentMap, EnemyManager& enemyManager);
	void initall();
	void updatemap(View& v, Player& p, EnemyManager& enemyManager);
	void coliM(Player& p);
	void coliD(Player& p);
	void coliKey(Player& p);
	void tpTxt(Player& p);
	void pnjTxt(Player& p);
	void eDonj(Player& p, View& v, string& currentMap);
	void DialPnj(Player& p);
	void coliE(EnemyManager& enemyManager);

	RenderWindow& window;//ajouter �a dans le game pour appeler la window et commencer la boucle de jeux  Map map; /*map.initM(); while (map.window) {}*/
	Texture txtArbre, txtSext, txtTour, txtPnj, txtTombe, txtChemin, txtMu, txtS, txtP, txtKeyB, txtTpG, txtTpD, txtPp_dmg, txtPp_vie, txtSd, txtPf, txtMais;
	Sprite sprtMu, sprtS, sprtP, sprtKeyB, sprtArbre, sprtSext, sprtPnj, sprtTombe, sprtChemin, sprtTour, sprtTpG, sprtTpD, sprtPp_dmg, sprtPp_vie, sprtSd, sprtPf, sprtMais;
	Font fI;
	Text interactTp, inetractPnj,dialogueAc;
	vector <string>vM;
	vector<unique_ptr<RectangleShape>>vMur;
	vector<unique_ptr<RectangleShape>>vSol;
	vector<unique_ptr<RectangleShape>>vPorte;
	vector<unique_ptr<RectangleShape>>vTp;
	vector<unique_ptr<RectangleShape>>dD;
	vector<unique_ptr<RectangleShape>>vMurext;
	//vector <shared_ptr<Patroler>>vE;
	vector <unique_ptr<RectangleShape>>vPnj;
	vector <unique_ptr<RectangleShape>>vKey;
	vector<RectangleShape>utilitaire;
};
