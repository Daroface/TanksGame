#include "Map.h"


using namespace sf;
using namespace std;

Map::Map(string path, int h, int w, Vector2i c):GameObject(path, h, w, c)
{

}
Map::Map()
{

}

int Map::decre()
{
	return 0;
}

int Map::getLife()
{
	return 0;
}

void Map::move(Vector2f x)
{

}


Sprite Map::turnObject(Vector2f x)
{
	return img;
}

Vector2i Map::getRot()
{
	return Vector2i(0, 0);
}

Map::~Map()
{

}

