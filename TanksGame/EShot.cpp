#include "EShot.h"

using namespace sf;
using namespace std;

EShot::EShot(string path, int h, int w, Vector2i c, Vector2i r) :GameObject(path, h, w, c)
{
	rotation = r;
}

EShot::EShot()
{
}
int EShot::decre()
{
	return 0;
}

int EShot::getLife() 
{
	return 0;
}

void EShot::move(Vector2f x)
{
	cor.x = cor.x + x.x;
	cor.y = cor.y + x.y;


	img.move(x);

}

Sprite EShot::turnObject(Vector2f x)
{
	return img;
}
Vector2i EShot::getRot()
{
	return rotation;
}

EShot::~EShot()
{

}