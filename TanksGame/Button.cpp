#include "Button.h"

using namespace sf;

Button::Button(std::string path, int w, int h, float x, float y)
{
	//ustawienie wymiarów
	width = w;
	high = h;
	if (!img.loadFromFile(path))
		throw 1;
	tex.loadFromImage(img);
	spr.setTexture(tex);
	file = path;
	cor.x = x;
	cor.y = y;
	spr.setPosition(x, y);
}

Button::Button()
{

}

Button::Button(Button const & x)
{
	high = x.high;
	width = x.width;
	file = x.file;
	img.loadFromFile(file);
	tex.loadFromImage(img);
	spr.setTexture(tex);
	cor.x = x.cor.x;
	cor.y = x.cor.y;
	spr.setPosition(cor.x, cor.y);

	
}

Sprite Button::buttonSelected()
{
	img.loadFromFile(SelectedButton);
	tex.update(img);
	spr.setTexture(tex);
	return spr;
}

Sprite Button::buttonNormal()
{
	img.loadFromFile(NormalButton);
	tex.update(img);
	spr.setTexture(tex);
	return spr;
}

Sprite Button::getButton()
{
	return spr;
}

Vector2f Button::position()
{
	return cor;
}