#pragma once
#include <SFML\Graphics.hpp>
#include <string>


using namespace sf;
using namespace std;

class GameObject
{
protected:
	//�cie�ka do pliku
	string plik;
	//wsp�rz�dne
	Vector2f cor;
	//Obraz
	Image tmp;
	//Tekstura
	Texture tex;
	//Sprite
	Sprite img;
	//szeroko��
	int width;
	//d�ugo��
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
	//odczyt wsp�rz�dnych
	virtual Vector2f getCor();
	//odczyt wysoko�ci
	virtual int getHigh();
	//odczyt d�ugo�ci
	virtual int getWidth();
	//dekrementacja �ycia
	virtual int decre() = 0;
	//odczyt �ycia
	virtual int getLife() = 0;
	//obr�t obiektu
	virtual Sprite turnObject(Vector2f x) = 0;
	//odczyt rotacji
	virtual Vector2i getRot() = 0;
	//destruktor
	~GameObject();

};
