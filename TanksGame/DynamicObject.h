#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "PShot.h"
#include "EShot.h"
#include <string>
#include <vector>
#include <windows.h>
#include <iostream>

using namespace sf;
using namespace std;

const int n = 768;
const int m = 1024;

class DynamicObject
{
	Player* player;
	vector<Enemy*> enemies;
	vector<Enemy*>::iterator enemiesIter;
	vector<PShot*> playerShot;
	vector<PShot*>::iterator playerShotIter;
	vector<EShot*> enemyShot;
	vector<EShot*>::iterator enemyShotIter;
	int aoe;
	int aob;
	int aoeb;
public:
	//konstruktor
	DynamicObject();
	//dodawanie obiektów typu Player
	void addPlayer(string path, int h, int w, Vector2i c);
	//usuniêcie obiektu typu Player
	void delPlayer();
	//dodawanie obiektów typu Enemy
	void addEnemy(string path, int h, int w, Vector2i c);
	//dodawanie obiektów typu PShot
	void addPShot(string path, int h, int w, Vector2i c, Vector2i r);
	//dodawanie obiektów typu EShot
	void addEShot(string path, int h, int w, Vector2i c, Vector2i r);
	//odczyt iloœci pocisków gracza
	int getBullets();
	//odczyt iloœci pocisków przeciwnika
	int getEnemyBullets();
	//odczyt iloœci przeciwników
	int getAmountOfEnemies();
	//dekrementacja ¿ycia i usuniêcie obiektu typu Enemy
	vector<Enemy*> dec(int i);
	//dekrementacja ¿ycia gracza
	Player dec();
	//odczyt obiektu PShot
	PShot getPShot(int i);
	//odczyt obiektu EShot
	EShot getEShot(int i);
	//odczyt obiektu Player
	Player getPlayer();
	//odczyt obiektu Enemy
	Enemy getEnemy(int n);
	//obrót obiektu Enemy
	Enemy turnEnemy(Vector2f x, int n);
	//obrót obiektu Player
	Player turnPlayer(Vector2f x);
	//poruszanie siê przeciwników
	Enemy moveEnemy(Vector2f x, int n);
	//poruszanie siê gracza
	Player movePlayer(Vector2f x);
	//poruszanie siê pocisków gracza
	PShot movePShot(Vector2f x, int n);
	//poruszanie siê pocisków przeciwnika
	EShot moveEShot(Vector2f x, int n);
	//usuniêcie pociku gracza
	vector<PShot*> removePShot(int n);
	//usuniêcie pocisku przeciwnika
	vector<EShot*> removeEShot(int n);
	//destruktor
	~DynamicObject();
};