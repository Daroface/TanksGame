#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Player:public GameObject
{
	Vector2i rotation;
	int life;
	
public:
	Player(string path, int h, int w, Vector2i c);
	Player();
	virtual void move(Vector2f x);
	virtual int decre();
	virtual int getLife();
	virtual Sprite turnObject(Vector2f x);
	virtual Vector2i getRot();
	~Player();
};