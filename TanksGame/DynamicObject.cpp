#include "DynamicObject.h"

using namespace std;
using namespace sf;

DynamicObject::DynamicObject()
{
	aoe = 0;
	aob = 0;
	aoeb = 0;
}

void DynamicObject::addPlayer(string path, int h, int w, Vector2i c)
{
	player = new Player(path, h, w, c);
}

void DynamicObject::delPlayer()
{
	delete player;
}

void DynamicObject::addEnemy(string path, int h, int w, Vector2i c)
{
	aoe++;
	enemies.push_back((new Enemy(path, h, w, c)));
}

int DynamicObject::getAmountOfEnemies()
{
	return aoe;
}

Player DynamicObject::getPlayer()
{
	return (*player);
}

Enemy DynamicObject::getEnemy(int n)
{
	return (*enemies.at(n));
}

Enemy DynamicObject::turnEnemy(Vector2f x, int n)
{
	(*enemies.at(n)).turnObject(x);
	return (*enemies.at(n));

}

Player DynamicObject::turnPlayer(Vector2f x)
{
	(*player).turnObject(x);
	return (*player);
}

Enemy DynamicObject::moveEnemy(Vector2f x, int n)
{
	(*enemies.at(n)).move(x);
	return (*enemies.at(n));
}

Player DynamicObject::movePlayer(Vector2f x)
{
	(*player).move(x);
	return (*player);
}

vector<Enemy*> DynamicObject::dec(int i)
{
	(*enemies.at(i)).decre();
	delete (enemies.at(i));
	enemiesIter = enemies.begin();
	enemiesIter += i;
	enemies.erase(enemiesIter);
	aoe--;
	return enemies;
}

Player DynamicObject::dec()
{
	(*player).decre();
	return (*player);
}

void DynamicObject::addEShot(string path, int h, int w, Vector2i c, Vector2i r)
{
	aoeb++;
	enemyShot.push_back((new EShot(path, h, w, c, r)));
}

void DynamicObject::addPShot(string path, int h, int w, Vector2i c, Vector2i r)
{
	aob++;
	PShot* tmp = new PShot(path, h, w, c, r);
	playerShot.push_back(tmp);
}

PShot DynamicObject::getPShot(int i)
{
	return (*playerShot.at(i));
}

EShot DynamicObject::getEShot(int i)
{
	return (*enemyShot.at(i));
}

EShot DynamicObject::moveEShot(Vector2f x, int n)
{
	(*enemyShot.at(n)).move(x);
	return (*enemyShot.at(n));
}

PShot DynamicObject::movePShot(Vector2f x, int n)
{
	(*playerShot.at(n)).move(x);
	return (*playerShot.at(n));
}

vector<EShot*> DynamicObject::removeEShot(int n)
{
	delete (enemyShot.at(n));
	enemyShotIter = enemyShot.begin();
	enemyShotIter += n;
	enemyShot.erase(enemyShotIter);
	aoeb--;
	return enemyShot;
}

vector<PShot*> DynamicObject::removePShot(int n)
{
	delete (playerShot.at(n));
	playerShotIter = playerShot.begin();
	playerShotIter += n;
	playerShot.erase(playerShotIter);
	aob--;
	return playerShot;
}

int DynamicObject::getBullets()
{
	return aob;
}

int DynamicObject::getEnemyBullets()
{
	return aoeb;
}

DynamicObject::~DynamicObject()
{
	enemies.clear();
	playerShot.clear();
	enemyShot.clear();
}