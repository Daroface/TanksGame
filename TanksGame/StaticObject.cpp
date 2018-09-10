#include "StaticObject.h"

using namespace sf;
using namespace std;

StaticObject::StaticObject()
{
	aow = 0;
}

void StaticObject::addMap(string path, int h, int w, Vector2i c)
{
	map = new Map(path, h, w, c);	
}

void StaticObject::addWall(string path, int h, int w, Vector2i c)
{
	aow++;
	walls.push_back((new Wall(path, h, w, c)));
}

void StaticObject::addEagle(string path, int h, int w, Vector2i c)
{
	eagle = new Eagle(path, h, w, c);
}

Eagle StaticObject::dec()
{
	(*eagle).decre();
	return (*eagle);
}

Map StaticObject::getMap()
{
	return *map;
}

Eagle StaticObject::getEagle()
{
	return *eagle;
}

Wall StaticObject::getWall(int n)
{
	wallsIter = walls.begin();
	wallsIter = wallsIter + n;
	return **wallsIter;
}

int StaticObject::amountOfWalls()
{
	return aow;
}

vector<Wall*> StaticObject::delWall()
{
	for (int i = 0;i < aow;i++)
	{
		delete walls.at(i);
	}
	return walls;
}

StaticObject::~StaticObject()
{
	delete map;
	delete eagle;
	delWall();
	walls.clear();
}