#include "Player.h"

using namespace sf;
using namespace std;

Player::Player(string path, int h, int w, Vector2i c):GameObject(path, h, w, c)
{
	rotation.x = 0;
	rotation.y = 0;
	life = 1;
}

Player::Player()
{
}

void Player::move(Vector2f x)
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
			else if(x.y < 0)
			{
				rotation.x = 0;
			}
		
			img.move(x);
		}
}

Sprite Player::turnObject(Vector2f x)
{
	
	if (x.x > 0 && rotation.y != 90)
	{
		tmp.loadFromFile("Images\\Objects\\playerr.png");
		tex.update(tmp);
		img.setTexture(tex);
		rotation.y=90;
		return img;
	}
	else if (x.x < 0 && rotation.y != 270)
	{
		tmp.loadFromFile("Images\\Objects\\playerl.png");
		tex.update(tmp);
		img.setTexture(tex);
		rotation.y = 270;
		return img;			
	}
	else if (x.y > 0 && rotation.y != 180)
		{
			tmp.loadFromFile("Images\\Objects\\playerd.png");
			tex.update(tmp);
			img.setTexture(tex);
			rotation.y = 180;
			return img;
		}
	else if (x.y < 0 && rotation.y != 0)
		{
			tmp.loadFromFile("Images\\Objects\\playeru.png");
			tex.update(tmp);
			img.setTexture(tex);
			rotation.y = 0;
			return img;
		}
	return img;
}

Vector2i Player::getRot()
{
	return rotation;
}

int Player::decre()
{
	life--;
	return life;
}

int Player::getLife()
{
	return life;
}

Player::~Player()
{

}