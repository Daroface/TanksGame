#include "SingleGame.h"

using namespace sf;
using namespace std;

SingleGame::SingleGame(RenderWindow& w):window(w)
{
	staticObjects = new StaticObject();
	dynamicObjects = new DynamicObject();
	mapcoord = Vector2i(0, 0);
	eaglecoord = Vector2i(492, 710);
	playercoor = Vector2i(552, 710);
	playerTime = true;	
}

void SingleGame::show()
{
	window.clear();
	window.draw(((*staticObjects).getMap().draw()));
	window.draw(((*staticObjects).getEagle().draw()));
	for (int i = 0;i < (*staticObjects).amountOfWalls();i++)
	{
		window.draw(((*staticObjects).getWall(i).draw()));
	}
	for (int i = 0;i < (*dynamicObjects).getBullets();i++)
	{
		window.draw(((*dynamicObjects).getPShot(i).draw()));
	}
	for (int i = 0;i < (*dynamicObjects).getEnemyBullets();i++)
	{
		window.draw(((*dynamicObjects).getEShot(i).draw()));
	}
	int gete = (*dynamicObjects).getAmountOfEnemies();
	if (gete > 2)
	{
		gete = 2;
	}
	for (int i = 0;i < gete;i++)
	{
		window.draw(((*dynamicObjects).getEnemy(i).draw()));
	}
	window.draw((*dynamicObjects).getPlayer().draw());
	window.display();
}

void SingleGame::play()
{
	int x[2], type;
	ifstream plik;
	plik.open("Walls\\w.txt");
	try
	{
		if (!plik.is_open())
			throw 0;
	}
	catch(int &e)
	{
		RenderWindow w(VideoMode(600, 300), "Error!", Style::Close);
		w.clear(Color::White);
		Text2 com("Brak pliku Walls\\w.txt", 160, 100);
		w.draw(com.get_text());
		w.display();
		while (w.isOpen())
		{

			Event ev;
			while (w.pollEvent(ev))
			{
				if (ev.type == Event::Closed)
				{
					w.close();
					window.close();
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					w.close();
					window.close();
				}
			}

		}
		exit(0);
	}
	try
	{
		while (!plik.eof())
		{
			plik >> x[0];
			plik >> x[1];
			if ((*staticObjects).amountOfWalls() == 2)
			{
				(*staticObjects).addWall(Wall2URL, 64, 10, Vector2i(x[0], x[1]));
			}
			else
				(*staticObjects).addWall(WallURL, 460, 530, Vector2i(x[0], x[1]));
			
		}
	}
	catch (int &e)
	{
		RenderWindow w(VideoMode(600, 300), "Error!", Style::Close);
		w.clear(Color::White);
		Text2 com("Brak pliku Images\\Objects\\left.png\n\t\t\t lub protect.png", 20, 100);
		w.draw(com.get_text());
		w.display();
		while (w.isOpen())
		{

			Event ev;
			while (w.pollEvent(ev))
			{
				if (ev.type == Event::Closed)
				{
					w.close();
					window.close();
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					w.close();
					window.close();
				}
			}
			
		}
		exit(0);
	}
	plik.close();
	//rysowanie i tworzenie obiektów gry
	(*staticObjects).addMap(MapURL, 1024, 768, mapcoord);
	try
	{
		(*staticObjects).addEagle(EagleURL, 40, 40, eaglecoord);
	}
	catch (int &e)
	{
		RenderWindow w(VideoMode(600, 300), "Error!", Style::Close);
		w.clear(Color::White);
		Text2 com("Brak pliku Images\\Objects\\eagle.png", 20, 100);
		w.draw(com.get_text());
		w.display();
		while (w.isOpen())
		{

			Event ev;
			while (w.pollEvent(ev))
			{
				if (ev.type == Event::Closed)
				{
					w.close();
					window.close();
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					w.close();
					window.close();
				}
			}

		}
		exit(0);
	}
	try
	{
		(*dynamicObjects).addPlayer(PlayeruURL, 40, 40, playercoor);
	}
	catch (int &e)
	{
		RenderWindow w(VideoMode(600, 300), "Error!", Style::Close);
		w.clear(Color::White);
		Text2 com("Brak pliku Images\\Objects\\playeru.png", 20, 100);
		w.draw(com.get_text());
		w.display();		
		while (w.isOpen())
		{
			
			Event ev;
			while (w.pollEvent(ev))
			{
				if (ev.type == Event::Closed)
				{
					w.close();
					window.close();
				}
				if(Keyboard::isKeyPressed(Keyboard::Escape))
				{
					w.close();
					window.close();
				}
			}
			
		}
		exit(0);
	}
	(*dynamicObjects).addEnemy(EnemyURL, 40, 40, Vector2i(20, 20));
	(*dynamicObjects).addEnemy(EnemyURL, 40, 40, Vector2i(960, 20));
	(*dynamicObjects).addEnemy(EnemyURL, 40, 40, Vector2i(20, 20));
	(*dynamicObjects).addEnemy(EnemyURL, 40, 40, Vector2i(960, 20));
	addTimer(2);
	show();

	//rozpoczêcie przechwytywania zdarzeñ
	Event ev;	
	int close = 0;
	while (window.isOpen())
	{		
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
			{
				close = 1;
			}		
		}	
		
		controlPlayer();
		controlEnemies();
		moveBullets();

			//Sprawdzanie zakoñczeñ:

			//zgin¹³ orze³ek - przegraliœmy
			if (checkEagle() == false)
			{
				window.clear();
				window.draw(((*staticObjects).getMap().draw()));
				for (int i = 0;i < (*staticObjects).amountOfWalls();i++)
				{
					window.draw(((*staticObjects).getWall(i).draw()));
				}
				for (int i = 0;i < (*dynamicObjects).getBullets();i++)
				{
					window.draw(((*dynamicObjects).getPShot(i).draw()));
				}
				window.draw((*dynamicObjects).getPlayer().draw());
				window.display();

				(*dynamicObjects).delPlayer();
				int end = (*dynamicObjects).getAmountOfEnemies();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).dec(0);
				}
				end = (*dynamicObjects).getBullets();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).removePShot(0);
				}
				end = (*dynamicObjects).getEnemyBullets();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).removeEShot(0);
				}
				RenderWindow w(VideoMode(400, 300), "Koniec gry!", Style::Close);
				w.clear(Color::Red);
				Text2 *com = new Text2("PRZEGRALES!!!", 100, 100);
				w.draw((*com).get_text());
				w.display();
				while (w.isOpen())
				{

					Event ev;
					while (w.pollEvent(ev))
					{
						if (ev.type == Event::Closed)
						{
							delete com;
							w.close();
						}
						if (Keyboard::isKeyPressed(Keyboard::Escape))
						{
							delete com;
							w.close();
						}
					}

				}
				Sleep(8000);
				break;
			}

			//zgin¹³ gracz - przegraliœmy
			if ((*dynamicObjects).getPlayer().getLife() == 0)
			{
				window.clear();
				window.draw(((*staticObjects).getMap().draw()));
				for (int i = 0;i < (*staticObjects).amountOfWalls();i++)
				{
					window.draw(((*staticObjects).getWall(i).draw()));
				}
				for (int i = 0;i < (*dynamicObjects).getBullets();i++)
				{
					window.draw(((*dynamicObjects).getPShot(i).draw()));
				}
				window.draw((*staticObjects).getEagle().draw());
				window.display();
				(*dynamicObjects).delPlayer();
				int end = (*dynamicObjects).getAmountOfEnemies();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).dec(0);
				}
				end = (*dynamicObjects).getBullets();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).removePShot(0);
				}
				end = (*dynamicObjects).getEnemyBullets();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).removeEShot(0);
				}
				RenderWindow w(VideoMode(400, 300), "Koniec gry!", Style::Close);
				w.clear(Color::Red);
				Text2 com("PRZEGRALES!!!", 100, 100);
				w.draw(com.get_text());
				w.display();
				while (w.isOpen())
				{

					Event ev;
					while (w.pollEvent(ev))
					{
						if (ev.type == Event::Closed)
						{
							w.close();
						}
						if (Keyboard::isKeyPressed(Keyboard::Escape))
						{
							w.close();
						}
					}

				}
				Sleep(8000);
				break;
			}
			
			//wszyscy przeciwnicy zgineli - wygraliœmy
			if ((*dynamicObjects).getAmountOfEnemies() == 0)
			{
				(*dynamicObjects).delPlayer();
				int end = (*dynamicObjects).getBullets();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).removePShot(0);
				}
				end = (*dynamicObjects).getEnemyBullets();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).removeEShot(0);
				}
				RenderWindow w(VideoMode(400, 300), "Koniec gry!", Style::Close);
				w.clear(Color::Green);
				Text2 com("WYGRALES!!!", 100, 100);
				w.draw(com.get_text());
				w.display();
				while (w.isOpen())
				{

					Event ev;
					while (w.pollEvent(ev))
					{
						if (ev.type == Event::Closed)
						{
							w.close();
						}
						if (Keyboard::isKeyPressed(Keyboard::Escape))
						{
							w.close();
						}
					}

				}
				Sleep(8000);
				break;
			}
			
			//Naciœniêcie zamkniêcia
			if (close == 1)
			{
				window.clear();
				window.draw(((*staticObjects).getMap().draw()));
				for (int i = 0;i < (*staticObjects).amountOfWalls();i++)
				{
					window.draw(((*staticObjects).getWall(i).draw()));
				}
				for (int i = 0;i < (*dynamicObjects).getBullets();i++)
				{
					window.draw(((*dynamicObjects).getPShot(i).draw()));
				}
				window.draw((*dynamicObjects).getPlayer().draw());
				window.display();
				(*staticObjects).dec();
				(*dynamicObjects).delPlayer();
				int end = (*dynamicObjects).getAmountOfEnemies();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).dec(0);
				}
				end = (*dynamicObjects).getBullets();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).removePShot(0);
				}
				end = (*dynamicObjects).getEnemyBullets();
				for (int i = 0;i < end;i++)
				{
					(*dynamicObjects).removeEShot(0);
				}
				
				Sleep(8000);
				break;
			}
			show();
		
	}

}

void SingleGame::playerTimer()
{
	this_thread::sleep_for(chrono::seconds(3));
	playerTime = true;
}

void SingleGame::addTimer(int n)
{
	for (int i = 0;i < n;i++)
	{
		enemyTime.push_back(true);
	}
}

void SingleGame::enemyTimer(int n)
{
	this_thread::sleep_for(chrono::seconds(8));
	enemyTime.at(n) = true;
}

DynamicObject SingleGame::controlPlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if ((*dynamicObjects).getPlayer().getRot().y != 180)
		{
			(*dynamicObjects).turnPlayer(Vector2f(0, 5));
		}
		else
		{
			if (checkCollision(Vector2f(0, 5)))
			{
				(*dynamicObjects).movePlayer(Vector2f(0, 5));
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if ((*dynamicObjects).getPlayer().getRot().y != 0)
		{
			(*dynamicObjects).turnPlayer(Vector2f(0, -5));
		}
		else
		{
			if (checkCollision(Vector2f(0, -5)))
			{
				(*dynamicObjects).movePlayer(Vector2f(0, -5));
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if ((*dynamicObjects).getPlayer().getRot().y != 90)
		{
			(*dynamicObjects).turnPlayer(Vector2f(5, 0));
		}
		else
		{
			if (checkCollision(Vector2f(5, 0)))
			{
				(*dynamicObjects).movePlayer(Vector2f(5, 0));
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if ((*dynamicObjects).getPlayer().getRot().y != 270)
		{
			(*dynamicObjects).turnPlayer(Vector2f(-5, 0));
		}
		else
		{
			if (checkCollision(Vector2f(-5, 0)))
			{
				(*dynamicObjects).movePlayer(Vector2f(-5, 0));
			}
		}
	}
		
	if (Keyboard::isKeyPressed(Keyboard::Space) && playerTime==true)
	{
			Vector2i tmp;
			if ((*dynamicObjects).getPlayer().getRot().y == 0)
			{
				tmp.x = (*dynamicObjects).getPlayer().getCor().x + 18;
				tmp.y = (*dynamicObjects).getPlayer().getCor().y;
				(*dynamicObjects).addPShot(Bullet, 4, 4, tmp, (*dynamicObjects).getPlayer().getRot());
			}
			else if ((*dynamicObjects).getPlayer().getRot().y == 90)
			{
				tmp.x = (*dynamicObjects).getPlayer().getCor().x + 40;
				tmp.y = (*dynamicObjects).getPlayer().getCor().y + 18;
				(*dynamicObjects).addPShot(Bullet, 4, 4, tmp, (*dynamicObjects).getPlayer().getRot());
			}
			else if ((*dynamicObjects).getPlayer().getRot().y == 180)
			{
				tmp.x = (*dynamicObjects).getPlayer().getCor().x + 18;
				tmp.y = (*dynamicObjects).getPlayer().getCor().y + 40;
				(*dynamicObjects).addPShot(Bullet, 4, 4, tmp, (*dynamicObjects).getPlayer().getRot());
			}
			else if ((*dynamicObjects).getPlayer().getRot().y == 270)
			{
				tmp.x = (*dynamicObjects).getPlayer().getCor().x;
				tmp.y = (*dynamicObjects).getPlayer().getCor().y + 18;
				(*dynamicObjects).addPShot(Bullet, 4, 4, tmp, (*dynamicObjects).getPlayer().getRot());
			}
			playerTime = false;
			thread t1(&SingleGame::playerTimer, this);
			t1.detach();
		}
	return (*dynamicObjects);
}

DynamicObject SingleGame::controlEnemies()
{
	srand(time(NULL));
	//zmienna sprawdzaj¹ca czy iloœæ przeciwników na mapie nie jest wiêksza od 2
	int gete= (*dynamicObjects).getAmountOfEnemies();
	if ((*dynamicObjects).getAmountOfEnemies() > 2)
	{
		gete = 2;
	}
	
	//Poruszanie siê

	for (int i = 0;i <gete;i++)
	{
		bool needChange = false;
		switch ((*dynamicObjects).getEnemy(i).getRot().y)
		{
			case 0:
			{
				if (checkEnemyCollision(Vector2f(0, -5), i))
				{
					(*dynamicObjects).moveEnemy(Vector2f(0, -5), i);
				}
				else
				{
					needChange = true;
				}
				break;
			}

			case 90:
			{
				if (checkEnemyCollision(Vector2f(0, 5), i))
				{
					(*dynamicObjects).turnEnemy(Vector2f(0, 5), i);
					(*dynamicObjects).moveEnemy(Vector2f(0, 5), i);
				}
				else if (checkEnemyCollision(Vector2f(5, 0), i))
				{
					(*dynamicObjects).moveEnemy(Vector2f(5, 0), i);
				}
				else
				{
					needChange = true;
				}
				break;
			}

			case 180:
			{
				if (checkEnemyCollision(Vector2f(0, 5), i))
				{
					(*dynamicObjects).turnEnemy(Vector2f(0, 5), i);
					(*dynamicObjects).moveEnemy(Vector2f(0, 5), i);
				}
				else if (checkEnemyCollision(Vector2f(0, 5), i))
				{
					(*dynamicObjects).moveEnemy(Vector2f(0, 5), i);
				}
				else
				{
					needChange = true;
				}
				break;
			}

			case 270:
			{
				if (checkEnemyCollision(Vector2f(0, 5), i))
				{
					(*dynamicObjects).turnEnemy(Vector2f(0, 5), i);
					(*dynamicObjects).moveEnemy(Vector2f(0, 5), i);
				}
				else if (checkEnemyCollision(Vector2f(-5, 0), i))
				{
					(*dynamicObjects).moveEnemy(Vector2f(-5, 0), i);
				}
				else
				{
					needChange = true;
				}
				break;
			}
		}

		while (needChange == true)
		{
			int choice = 0;
			choice = (rand() % 4) + 1;

			switch (choice)
			{
				case 1:
				{
					if (checkEnemyCollision(Vector2f(0, -5), i))
					{
						if ((*dynamicObjects).getEnemy(i).getRot().y != 0)
						{
							(*dynamicObjects).turnEnemy(Vector2f(0, -5), i);
						}
						(*dynamicObjects).moveEnemy(Vector2f(0, -5), i);
						needChange = false;
					}
					break;
				}

				case 2:
				{
					if (checkEnemyCollision(Vector2f(0, 5), i))
					{
						if ((*dynamicObjects).getEnemy(i).getRot().y != 180)
						{
							(*dynamicObjects).turnEnemy(Vector2f(0, 5), i);
						}
						(*dynamicObjects).moveEnemy(Vector2f(0, 5), i);
						needChange = false;
					}
					break;
				}

				case 3:
				{
					if (checkEnemyCollision(Vector2f(5, 0), i))
					{
						if ((*dynamicObjects).getEnemy(i).getRot().y != 90)
						{
							(*dynamicObjects).turnEnemy(Vector2f(5, 0), i);
						}
						(*dynamicObjects).moveEnemy(Vector2f(5, 0), i);
						needChange = false;
					}
					break;
				}

				case 4:
				{
					if (checkEnemyCollision(Vector2f(-5, 0), i))
					{
						if ((*dynamicObjects).getEnemy(i).getRot().y != 270)
						{
							(*dynamicObjects).turnEnemy(Vector2f(-5, 0), i);
						}
						(*dynamicObjects).moveEnemy(Vector2f(-5, 0), i);
						needChange = false;
					}
					break;
				}
			}
		}		
	}

	//Strzelanie
	
		for (int i = 0;i < gete;i++)
		{
			if (enemyTime.at(i) == true)
			{
			Vector2i tmp;
			if ((*dynamicObjects).getEnemy(i).getRot().y == 0)
			{
				tmp.x = (*dynamicObjects).getEnemy(i).getCor().x + 18;
				tmp.y = (*dynamicObjects).getEnemy(i).getCor().y;
				(*dynamicObjects).addEShot(Bullet, 4, 4, tmp, (*dynamicObjects).getEnemy(i).getRot());
			}
			else if ((*dynamicObjects).getEnemy(i).getRot().y == 90)
			{
				tmp.x = (*dynamicObjects).getEnemy(i).getCor().x + 40;
				tmp.y = (*dynamicObjects).getEnemy(i).getCor().y + 18;
				(*dynamicObjects).addEShot(Bullet, 4, 4, tmp, (*dynamicObjects).getEnemy(i).getRot());
			}
			else if ((*dynamicObjects).getEnemy(i).getRot().y == 180)
			{
				tmp.x = (*dynamicObjects).getEnemy(i).getCor().x + 18;
				tmp.y = (*dynamicObjects).getEnemy(i).getCor().y + 40;
				(*dynamicObjects).addEShot(Bullet, 4, 4, tmp, (*dynamicObjects).getEnemy(i).getRot());
			}
			else if ((*dynamicObjects).getPlayer().getRot().y == 270)
			{
				tmp.x = (*dynamicObjects).getEnemy(i).getCor().x;
				tmp.y = (*dynamicObjects).getEnemy(i).getCor().y + 18;
				(*dynamicObjects).addEShot(Bullet, 4, 4, tmp, (*dynamicObjects).getEnemy(i).getRot());
			}
			enemyTime.at(i) = false;
			thread t2(bind(&SingleGame::enemyTimer, this, i));
			t2.detach();
		}
		
	}

	return (*dynamicObjects);
}

DynamicObject SingleGame::moveBullets()
{
	if ((*dynamicObjects).getBullets() > 0)
	{
		for (int i = 0;i < (*dynamicObjects).getBullets();i++)
		{
			switch ((*dynamicObjects).getPShot(i).getRot().y)
			{
			case 0:
			{
				playerCollision = false;

				checkBulletCollision(Vector2f(0, -10), i);
				if (playerCollision == false)
				{
					(*dynamicObjects).movePShot(Vector2f(0, -10), i);
				}
				else
				{
					(*dynamicObjects).removePShot(i);
				}
				break;
			}

			case 90:
			{
				playerCollision = false;

				checkBulletCollision(Vector2f(10, 0), i);
				if (playerCollision == false)
				{
					(*dynamicObjects).movePShot(Vector2f(10, 0), i);
				}
				else
				{
					(*dynamicObjects).removePShot(i);
				}
				break;
			}

			case 180:
			{
				playerCollision = false;

				checkBulletCollision(Vector2f(0, 10), i);
				if (playerCollision == false)
				{
					(*dynamicObjects).movePShot(Vector2f(0, 10), i);
				}
				else
				{
					(*dynamicObjects).removePShot(i);
				}
				break;
			}

			case 270:
			{
				playerCollision = false;

				checkBulletCollision(Vector2f(-10, 0), i);
				if (playerCollision == false)
				{
					(*dynamicObjects).movePShot(Vector2f(-10, 0), i);
				}
				else
				{
					(*dynamicObjects).removePShot(i);
				}
				break;
			}
			}
		}
	}

	if ((*dynamicObjects).getEnemyBullets() > 0)
	{
		for (int i = 0;i < (*dynamicObjects).getEnemyBullets();i++)
		{
			switch ((*dynamicObjects).getEShot(i).getRot().y)
			{
			case 0:
			{
				enemyCollision = false;

				checkEnemyBulletCollision(Vector2f(0, -10), i);
				if (enemyCollision == false)
				{
					(*dynamicObjects).moveEShot(Vector2f(0, -10), i);
				}
				else
				{
					(*dynamicObjects).removeEShot(i);
				}
				break;
			}

			case 90:
			{
				enemyCollision = false;

				checkEnemyBulletCollision(Vector2f(10, 0), i);
				if (enemyCollision == false)
				{
					(*dynamicObjects).moveEShot(Vector2f(10, 0), i);
				}
				else
				{
					(*dynamicObjects).removeEShot(i);
				}
				break;
			}

			case 180:
			{
				enemyCollision = false;

				checkEnemyBulletCollision(Vector2f(0, 10), i);
				if (enemyCollision == false)
				{
					(*dynamicObjects).moveEShot(Vector2f(0, 10), i);
				}
				else
				{
					(*dynamicObjects).removeEShot(i);
				}
				break;
			}

			case 270:
			{
				enemyCollision = false;

				checkEnemyBulletCollision(Vector2f(-10, 0), i);
				if (enemyCollision == false)
				{
					(*dynamicObjects).moveEShot(Vector2f(-10, 0), i);
				}
				else
				{
					(*dynamicObjects).removeEShot(i);
				}
				break;
			}
			}
		}
	}
	return (*dynamicObjects);
}

//Zarz¹dzanie kolizjami gracza

bool SingleGame::checkCollision(Vector2f v)
{
	playerCollision = false;
	Vector2f x = (*dynamicObjects).getPlayer().getCor();

	thread t1(bind(&SingleGame::checkWallCollision1, this, v, x));
	thread t2(bind(&SingleGame::checkWallCollision2, this, v, x));
	thread t3(bind(&SingleGame::checkWallCollision3, this, v, x));

	t1.join();
	t2.join();
	t3.join();


	if (playerCollision == true)
	{
		return false;
	}
	else
		return true;
}

//zarz¹dzanie kolizjami przeciwników

bool SingleGame::checkEnemyCollision(Vector2f v, int n)
{
	enemyCollision = false;
	Vector2f x = (*dynamicObjects).getEnemy(n).getCor();
	thread t1(bind(&SingleGame::checkEnemyWallCollision1, this, v, x));
	thread t2(bind(&SingleGame::checkEnemyWallCollision2, this, v, x));
	thread t3(bind(&SingleGame::checkEnemyWallCollision3, this, v, x));

	t1.join();
	t2.join();
	t3.join();


	if (enemyCollision == true)
	{
		return false;
	}
	else
		return true;
}

//###  Sprawdzanie kolizji dla gracza i jego pocisków  ###

void SingleGame::checkWallCollision1(Vector2f v, Vector2f x)
{
		float xx = x.x+v.x;
		float y = x.y+v.y;
	
		if (xx >= 17 && xx <= 480 && y <= 610 && y >= 43)
			playerCollision = true;
}

void SingleGame::checkWallCollision2(Vector2f v, Vector2f x)
{

	float xx = x.x + v.x;
	float y = x.y + v.y;


	if (xx >= 504 && xx <= 1004 && y <= 610 && y >= 43)
		playerCollision = true;
}

void SingleGame::checkWallCollision3(Vector2f v, Vector2f x)
{

	float xx = x.x + v.x;
	float y = x.y + v.y;

	if (xx >= 440 && xx <= 546 && y <= 700 && y >= 658)
		playerCollision = true;
	else if (xx + 40 >= 492 && xx <= 532 && y >= 710 && y <= 750)
		playerCollision = true;
}

void SingleGame::checkBulletCollision(Vector2f v, int i)
{
	float x = (*dynamicObjects).getPShot(i).getCor().x + v.x;
	float y = (*dynamicObjects).getPShot(i).getCor().y + v.y;


	if ((x > 1008) || (x < 13) || (y > 745) || (y < 13))
	{
		playerCollision = true;
	}
	else if ((*dynamicObjects).getPShot(i).draw().getGlobalBounds().intersects((*staticObjects).getEagle().draw().getGlobalBounds()))
	{
		playerCollision = true;
		(*staticObjects).dec();
	}
	else
	{
		for (int j = 0;j < (*staticObjects).amountOfWalls();j++)
		{
			if ((*dynamicObjects).getPShot(i).draw().getGlobalBounds().intersects((*staticObjects).getWall(j).draw().getGlobalBounds()))
			{
				playerCollision = true;
				break;
			}
		}
		if (playerCollision != true)
		{
			for (int j = 0;j < (*dynamicObjects).getAmountOfEnemies();j++)
			{
				if ((*dynamicObjects).getPShot(i).draw().getGlobalBounds().intersects((*dynamicObjects).getEnemy(j).draw().getGlobalBounds()))
				{
					playerCollision = true;
					(*dynamicObjects).dec(j);
					break;
				}
			}
		}
	}

}

//###  Sprawdzanie kolizji dla przeciwników i ich pocisków  ###

void SingleGame::checkEnemyWallCollision1(Vector2f v, Vector2f x)
{

	float xx = x.x + v.x;
	float y = x.y + v.y;

	if (xx >= 15 && xx <= 480 && y <= 610 && y >= 40)
		enemyCollision = true;
}

void SingleGame::checkEnemyWallCollision2(Vector2f v, Vector2f x)
{

	float xx = x.x + v.x;
	float y = x.y + v.y;

	if (xx >= 504 && xx <= 1004 && y <= 610 && y >= 43)
		enemyCollision = true;
}

void SingleGame::checkEnemyWallCollision3(Vector2f v, Vector2f x)
{

	float xx = x.x + v.x;
	float y = x.y + v.y;

	if (xx >= 440 && xx <= 546 && y <= 700 && y >= 658)
		enemyCollision = true;
	else if (xx + 40 >= 492 && xx <= 532 && y >= 710 && y <= 750)
		enemyCollision = true;
	else if ((xx > 968) || (xx < 13) || (y > 710) || (y < 13))
	{
		enemyCollision = true;
	}
}

void SingleGame::checkEnemyBulletCollision(Vector2f v, int i)
{
	float x = (*dynamicObjects).getEShot(i).getCor().x + v.x;
	float y = (*dynamicObjects).getEShot(i).getCor().y + v.y;


	if ((x > 1008) || (x < 13) || (y > 745) || (y < 13))
	{
		enemyCollision = true;
	}
	else if ((*dynamicObjects).getEShot(i).draw().getGlobalBounds().intersects((*staticObjects).getEagle().draw().getGlobalBounds()))
	{
		enemyCollision = true;
		(*staticObjects).dec();
	}
	else
	{
		for (int j = 0;j < (*staticObjects).amountOfWalls();j++)
		{
			if ((*dynamicObjects).getEShot(i).draw().getGlobalBounds().intersects((*staticObjects).getWall(j).draw().getGlobalBounds()))
			{
				enemyCollision = true;
				break;
			}
		}
		if (enemyCollision != true)
		{			
			if ((*dynamicObjects).getEShot(i).draw().getGlobalBounds().intersects((*dynamicObjects).getPlayer().draw().getGlobalBounds()))
			{
				enemyCollision = true;
				(*dynamicObjects).dec();
			}
			
		}
	}

}

bool SingleGame::checkEagle()
{
	if (((*staticObjects).getEagle()).getLife() == 0)
	{
		return false;
	}
	return true;
}

SingleGame::~SingleGame()
{
	delete staticObjects;
	delete dynamicObjects;
	enemyTime.clear();
}

