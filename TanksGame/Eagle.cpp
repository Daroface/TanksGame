#include "Eagle.h"

using namespace sf;
using namespace std;

Eagle::Eagle(string path, int h, int w, Vector2i c) :GameObject(path, h, w, c)
{
	life = 1;
}
Eagle::Eagle()
{

}

int Eagle::decre()
{
	life--;
	return life;
}

int Eagle::getLife()
{
	return life;
}

void Eagle::move(Vector2f x)
{
	life=0;
}

Sprite Eagle::turnObject(Vector2f x)
{
	return img;
}

Vector2i Eagle::getRot()
{
	return Vector2i(0,0);
}

Eagle::~Eagle()
{

}
