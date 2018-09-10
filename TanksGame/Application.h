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
	//wywo³anie okna
	Application();
	//g³ówna pêtla programu
	void run();
	//rysowanie menu
	void drawMenuOnScreen(Menu actual);
	//destruktor
	~Application();


};