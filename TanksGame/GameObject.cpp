#include "GameObject.h"

using namespace sf;
using namespace std;

GameObject::GameObject(string path, int h, int w, Vector2i c)
{
	plik = path;
	if (tmp.loadFromFile(path) != true)
	{
		throw 0;
	}
	tex.loadFromImage(tmp);
	img.setTexture(tex);	
	high = h;
	width = w;
	cor.x = c.x;
	cor.y = c.y;
	img.setPosition(cor);	
}

GameObject::GameObject()
{

}

Sprite GameObject::draw()
{
	return img;
}

Vector2f GameObject::getCor()
{
	return cor;
}

int GameObject::getHigh()
{
	return high;
}

int GameObject::getWidth()
{
	return width;
}

GameObject::~GameObject()
{

}
