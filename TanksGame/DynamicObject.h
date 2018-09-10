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
	//dodawanie obiekt�w typu Player
	void addPlayer(string path, int h, int w, Vector2i c);
	//usuni�cie obiektu typu Player
	void delPlayer();
	//dodawanie obiekt�w typu Enemy
	void addEnemy(string path, int h, int w, Vector2i c);
	//dodawanie obiekt�w typu PShot
	void addPShot(string path, int h, int w, Vector2i c, Vector2i r);
	//dodawanie obiekt�w typu EShot
	void addEShot(string path, int h, int w, Vector2i c, Vector2i r);
	//odczyt ilo�ci pocisk�w gracza
	int getBullets();
	//odczyt ilo�ci pocisk�w przeciwnika
	int getEnemyBullets();
	//odczyt ilo�ci przeciwnik�w
	int getAmountOfEnemies();
	//dekrementacja �ycia i usuni�cie obiektu typu Enemy
	vector<Enemy*> dec(int i);
	//dekrementacja �ycia gracza
	Player dec();
	//odczyt obiektu PShot
	PShot getPShot(int i);
	//odczyt obiektu EShot
	EShot getEShot(int i);
	//odczyt obiektu Player
	Player getPlayer();
	//odczyt obiektu Enemy
	Enemy getEnemy(int n);
	//obr�t obiektu Enemy
	Enemy turnEnemy(Vector2f x, int n);
	//obr�t obiektu Player
	Player turnPlayer(Vector2f x);
	//poruszanie si� przeciwnik�w
	Enemy moveEnemy(Vector2f x, int n);
	//poruszanie si� gracza
	Player movePlayer(Vector2f x);
	//poruszanie si� pocisk�w gracza
	PShot movePShot(Vector2f x, int n);
	//poruszanie si� pocisk�w przeciwnika
	EShot moveEShot(Vector2f x, int n);
	//usuni�cie pociku gracza
	vector<PShot*> removePShot(int n);
	//usuni�cie pocisku przeciwnika
	vector<EShot*> removeEShot(int n);
	//destruktor
	~DynamicObject();
};