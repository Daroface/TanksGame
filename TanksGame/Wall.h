#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include <string>
#include <iostream>

class Wall:public GameObject
{
public:
	Wall(string path, int h, int w, Vector2i c);
	Wall();
	virtual void move(Vector2f x);
	virtual Sprite turnObject(Vector2f x);
	virtual int decre();
	virtual int getLife();
	virtual Vector2i getRot();
	~Wall();
};