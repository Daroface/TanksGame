#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Font.h"

using namespace sf;
using namespace std;

class Text2: public Text
{
	string text_n;
	Text text;
	Font font;
	float cor_x;
	float cor_y;
public:
	//konstruktor
	Text2(string text_name, float x, float y);
	//konstruktor kopiuj¹cy
	Text2(Text2 const &x);
	//odczyt tekstu
	Text get_text();
	//destruktor
	~Text2();
	
};