#include "Text2.h"

using namespace sf;
using namespace std;

Text2::Text2(string text_name, float x, float y)
{
	font.loadFromFile("text\\Sansation.ttf");
	text_n = text_name;
	text.setString(text_n);
	text.setFillColor(Color::Black);
	text.setCharacterSize(30);
	text.setStyle(Bold);
	text.setFont(font);
	cor_x = x;
	cor_y = y;
	text.setPosition(cor_x, cor_y);
	
}

Text2::Text2(Text2 const &x)
{
	font.loadFromFile("text\\Sansation.ttf");
	text_n = x.text_n;
	text.setString(text_n);
	text.setFillColor(Color::Black);
	text.setCharacterSize(30);
	text.setStyle(Bold);
	text.setFont(font);
	cor_x = x.cor_x;
	cor_y = x.cor_y;
	text.setPosition(cor_x, cor_y);
}

Text Text2::get_text()
{
	return text;
}

Text2::~Text2()
{

}