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
	//usuni�cie obiketu typu Wall
	vector<Wall*> delWall();
	//dodanie obiektu typu Eagle
	void addEagle(string path, int h, int w, Vector2i c);
	//dekrementacja �ycia i usuni�cie orze�ka
	Eagle dec();
	//odczyt mapy
	Map getMap();
	//odczyt orze�ka
	Eagle getEagle();
	//odczyt �ciany
	Wall getWall(int n);
	//odczyt ilo�ci �cian
	int amountOfWalls();
	//destruktor
	~StaticObject();
	
};