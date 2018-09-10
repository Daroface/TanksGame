#pragma once
#include <SFML\Graphics.hpp>
#include <string>


using namespace sf;
using namespace std;

class GameObject
{
protected:
	//œcie¿ka do pliku
	string plik;
	//wspó³rzêdne
	Vector2f cor;
	//Obraz
	Image tmp;
	//Tekstura
	Texture tex;
	//Sprite
	Sprite img;
	//szerokoœæ
	int width;
	//d³ugoœæ
	int high;
public:
	//kostruktor 
	GameObject(string path, int h, int w, Vector2i c);
	//konstruktor bezparametrowy
	GameObject();
	//odczyt Sprite'a
	virtual Sprite draw();
	//ruch obiektu
	virtual void move(Vector2f x)=0;
	//odczyt wspó³rzêdnych
	virtual Vector2f getCor();
	//odczyt wysokoœci
	virtual int getHigh();
	//odczyt d³ugoœci
	virtual int getWidth();
	//dekrementacja ¿ycia
	virtual int decre() = 0;
	//odczyt ¿ycia
	virtual int getLife() = 0;
	//obrót obiektu
	virtual Sprite turnObject(Vector2f x) = 0;
	//odczyt rotacji
	virtual Vector2i getRot() = 0;
	//destruktor
	~GameObject();

};
