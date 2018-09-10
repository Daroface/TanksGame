#include "PShot.h"

using namespace sf;
using namespace std;

PShot::PShot(string path, int h, int w, Vector2i c, Vector2i r):GameObject(path, h, w, c)
{
	rotation = r;
}

PShot::PShot()
{
}

int PShot::decre()
{
	return 0;
}

int PShot::getLife()
{
	return 0;
}

void PShot::move(Vector2f x)
{
	cor.x = cor.x + x.x;
	cor.y = cor.y + x.y;

	
		img.move(x);
	
}

Sprite PShot::turnObject(Vector2f x)
{
	return img;
}

Vector2i PShot::getRot()
{
	return rotation;
}

PShot::~PShot()
{

}
