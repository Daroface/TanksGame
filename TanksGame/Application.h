#pragma once
#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <iostream>
#include <Windows.h>
using namespace sf;

class Application
{
	//okno
	RenderWindow window;
	//Obraz
	Image background;
	//Tekstura
	Texture btex;
	//Sprite
	Sprite bspr;
public:
	//wywo�anie okna
	Application();
	//g��wna p�tla programu
	void run();
	//rysowanie menu
	void drawMenuOnScreen(Menu actual);
	//destruktor
	~Application();


};