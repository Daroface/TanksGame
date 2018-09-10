#pragma once
#include <SFML\Graphics.hpp>
#include "Map.h"
#include "Wall.h"
#include "Eagle.h"
#include <string>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

class StaticObject
{
	Map* map;
	Eagle* eagle;
	vector<Wall*> walls;
	vector<Wall*>::iterator wallsIter;
	int aow;
public:
	//konstruktor
	StaticObject();
	//dodanie obiektu typu Map
	void addMap(string path, int h, int w, Vector2i c);
	//dodanie obiektu typu Wall
	void addWall(string path, int h, int w, Vector2i c);
	//usuniêcie obiketu typu Wall
	vector<Wall*> delWall();
	//dodanie obiektu typu Eagle
	void addEagle(string path, int h, int w, Vector2i c);
	//dekrementacja ¿ycia i usuniêcie orze³ka
	Eagle dec();
	//odczyt mapy
	Map getMap();
	//odczyt orze³ka
	Eagle getEagle();
	//odczyt œciany
	Wall getWall(int n);
	//odczyt iloœci œcian
	int amountOfWalls();
	//destruktor
	~StaticObject();
	
};