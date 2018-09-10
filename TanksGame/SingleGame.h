#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "StaticObject.h"
#include "DynamicObject.h"
#include "Map.h"
#include "Wall.h"
#include "Eagle.h"
#include "Player.h"
#include "Text2.h"
#include <iostream>
#include <thread>
#include <string>
#include <windows.h>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define MapURL "Images\\Background\\Background.png"
#define PlayeruURL "Images\\Objects\\playeru.png"
#define WallURL "Images\\Objects\\left.png"
#define Wall2URL "Images\\Objects\\protect.png"
#define EagleURL "Images\\Objects\\Eagle.png"
#define Bullet "Images\\Objects\\bullet.png"
#define EnemyURL "Images\\Objects\\enemyd.png"

using namespace sf;

class SingleGame
{
	RenderWindow& window;
	//stworzenie tablic statycznych i dynamicznych obiektów
	StaticObject* staticObjects;
	DynamicObject* dynamicObjects;
	bool playerCollision;
	bool enemyCollision;
	bool playerTime;
	vector<bool> enemyTime;
	//wspó³rzêdne obiektów mapa oraz orze³ek
	Vector2i mapcoord;
	Vector2i eaglecoord;
	Vector2i playercoor;
public:
	//konstruktor
	SingleGame(RenderWindow &w);
	//gra
	void play();
	//wyœwietlanie
	void show();
	//ruch pocisków
	DynamicObject moveBullets();
	//sterowanie graczem
	DynamicObject controlPlayer();
	//sterowanie przeciwnikiem
	DynamicObject controlEnemies();
	//timer 3sekundowy
	void playerTimer();
	//timer 8sekundowy
	void enemyTimer(int n);
	//dodanie nowego boola
	void addTimer(int n);
	//test czy orze³ek nie zosta³ zniszczony
	bool checkEagle();
	//sprawdzanie kolizji dla gracza i przeciwnika
	bool checkCollision(Vector2f v);
	bool checkEnemyCollision(Vector2f v, int n);
	void checkWallCollision1(Vector2f v, Vector2f x);
	void checkEnemyWallCollision1(Vector2f v, Vector2f x);
	void checkWallCollision2(Vector2f v, Vector2f x);
	void checkEnemyWallCollision2(Vector2f v, Vector2f x);
	void checkWallCollision3(Vector2f v, Vector2f x);
	void checkEnemyWallCollision3(Vector2f v, Vector2f x);
	//sprawdzanie kolizji dla pocisków gracza i przeciwnika
	void checkBulletCollision(Vector2f v, int i);
	void checkEnemyBulletCollision(Vector2f v, int i);
	//destruktor
	~SingleGame();

};