#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class EShot :public GameObject
{
	Vector2i rotation;

public:
	EShot(string path, int h, int w, Vector2i c, Vector2i r);
	EShot();
	virtual void move(Vector2f x);
	virtual int decre();
	virtual int getLife();
	virtual Sprite turnObject(Vector2f x);
	virtual Vector2i getRot();
	~EShot();
};