#include "Wall.h"

using namespace sf;
using namespace std;

Wall::Wall(string path, int h, int w, Vector2i c):GameObject(path, h, w, c)
{
}

Wall::Wall()
{

}

void Wall::move(Vector2f x)
{

}

Sprite Wall::turnObject(Vector2f x)
{
	return img;
}

Vector2i Wall::getRot()
{
	return Vector2i(0, 0);
}

int Wall::decre()
{
	return 0;
}

int Wall::getLife()
{
	return 0;
}

Wall::~Wall()
{

}