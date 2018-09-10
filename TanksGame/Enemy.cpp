#include "Enemy.h"

using namespace sf;
using namespace std;

Enemy::Enemy(string path, int h, int w, Vector2i c) :GameObject(path, h, w, c)
{
	rotation.x = 180;
	rotation.y = 180;
	life = 1;
}

Enemy::Enemy()
{

}

int Enemy::decre()
{
	life--;
	return life;
}

int Enemy::getLife()
{
	return life;
}

void Enemy::move(Vector2f x)
{
	cor.x = cor.x + x.x;
	cor.y = cor.y + x.y;

	if ((cor.x > 968) || (cor.x < 13) || (cor.y > 710) || (cor.y < 13))
	{
		cor.x = cor.x - x.x;
		cor.y = cor.y - x.y;
	}
	else
	{
		if (x.x > 0)
		{
			rotation.x = 90;
		}
		else if (x.x < 0)
		{
			rotation.x = 270;
		}
		else if (x.y > 0)
		{
			rotation.x = 180;
		}
		else if (x.y < 0)
		{
			rotation.x = 0;
		}
			
		img.move(x);
	}
}

Sprite Enemy::turnObject(Vector2f x)
{
	if (x.x > 0 && rotation.y != 90)
	{
		tmp.loadFromFile("Images\\Objects\\enemyr.png");
		tex.update(tmp);
		img.setTexture(tex);
		rotation.y = 90;
		return img;
	}
	else if (x.x < 0 && rotation.y != 270)
	{
		tmp.loadFromFile("Images\\Objects\\enemyl.png");
		tex.update(tmp);
		img.setTexture(tex);
		rotation.y = 270;
		return img;
	}
	else if (x.y > 0 && rotation.y != 180)
	{
		tmp.loadFromFile("Images\\Objects\\enemyd.png");
		tex.update(tmp);
		img.setTexture(tex);
		rotation.y = 180;
		return img;
	}
	else if (x.y < 0 && rotation.y != 0)
	{
		tmp.loadFromFile("Images\\Objects\\enemyu.png");
		tex.update(tmp);
		img.setTexture(tex);
		rotation.y = 0;
		return img;
	}
	return img;

}

Vector2i Enemy::getRot()
{
	return rotation;
}

Enemy::~Enemy()
{

}