#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

#define NormalButton "Images\\Buttons\\Button.png"
#define SelectedButton "Images\\Buttons\\Button_selected.png"

using namespace sf;

class Button
{
	//szerokoœæ
	int width;
	//d³ugoœæ
	int high;
	//wspó³rzêdne
	Vector2f cor;
	//obraz
	Image img;
	//Tekstura
	Texture tex;
	//Sprite
	Sprite spr;
	//œcie¿ka
	std::string file;
	
public:
	//konstruktor
	Button(std::string path, int w, int h, float x, float y);
	//kontstruktor bezparametrowy
	Button();
	//konstruktor kopiuj¹cy
	Button(Button const &x);
	//odczyt Sprite'a
	Sprite getButton();
	//ustawienie Sprite'a dla wybranego
	Sprite buttonSelected();
	//ustawienie Sprite'a dla normalnego
	Sprite buttonNormal();
	//odczyt pozycji
	Vector2f position();
	//destruktor
	~Button(){}
};
