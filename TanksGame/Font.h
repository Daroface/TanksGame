#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Fontt
{
	Font font;
public:
	Fontt()
	{
		font.loadFromFile("text\\Sansation.ttf");
	}
	Font get()
	{
		return font;
	}
};