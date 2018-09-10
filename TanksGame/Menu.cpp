#include "Menu.h"

using namespace sf;

Menu::Menu(int il)
{
	amount = il;
	change = 0;
}

int Menu::amountOfButtons()
{
	return amount;
}

int Menu::getChange()
{
	return change;
}

void Menu::add(Button *p, Text2 *t)
{
	list_menu.push_back(p);
	text_list_menu.push_back(t);
}

void Menu::mainmenu()
{
	//tworzenie przycisków
	Button *Player1 = new Button(SelectedButton, ButtonWidth, ButtonHigh, 340, 300);
	Text2 *Player1_text = new Text2("Start", 460, 322);
	
	Button *Settings = new Button(NormalButton, ButtonWidth, ButtonHigh, 340, 400);
	Text2 *Settings_text = new Text2("Ustawienia", 417, 422);

	Button *Exit = new Button(NormalButton, ButtonWidth, ButtonHigh, 340, 500);
	Text2 *Exit_text = new Text2("Wyjscie", 440, 522);


	//dodanie do menu;;
	add(Player1, Player1_text);
	add(Settings, Settings_text);
	add(Exit, Exit_text);
}

void Menu::settingmenu()
{
	//tworzenie przycisków
	Button *Up = new Button(NormalButton, ButtonWidth, ButtonHigh, 160, 100);
	Text2 *Up_text = new Text2("Gora", 268, 122);

	Button *Up_Key = new Button(NormalButton, ButtonWidth, ButtonHigh, 550, 100);
	Text2 *Up_Key_text = new Text2("Strzalka w gore", 595, 122);

	Button *Down = new Button(NormalButton, ButtonWidth, ButtonHigh, 160, 200);
	Text2 *Down_text = new Text2("Dol", 280, 222);

	Button *Down_Key = new Button(NormalButton, ButtonWidth, ButtonHigh, 550, 200);
	Text2 *Down_Key_text = new Text2("Strzalka w dol", 600, 222);

	Button *Left = new Button(NormalButton, ButtonWidth, ButtonHigh, 160, 300);
	Text2 *Left_text = new Text2("Lewo", 270, 322);

	Button *Left_Key = new Button(NormalButton, ButtonWidth, ButtonHigh, 550, 300);
	Text2 *Left_Key_text = new Text2("Strzalka w lewo", 590, 322);

	Button *Right = new Button(NormalButton, ButtonWidth, ButtonHigh, 160, 400);
	Text2 *Right_text = new Text2("Prawo", 265, 422);

	Button *Right_Key = new Button(NormalButton, ButtonWidth, ButtonHigh, 550, 400);
	Text2 *Right_Key_text = new Text2("Strzalka w prawo", 580, 422);

	Button *Attack = new Button(NormalButton, ButtonWidth, ButtonHigh, 160, 500);
	Text2 *Attack_text = new Text2("Atak", 272, 522);

	Button *Attack_Key = new Button(NormalButton, ButtonWidth, ButtonHigh, 550, 500);
	Text2 *Attack_Key_text = new Text2("Spacja", 650, 522);

	Button *Back = new Button(SelectedButton, ButtonWidth, ButtonHigh, 340, 600);
	Text2 *Back_text = new Text2("Powrot", 440, 622);

	//dodanie do menu;;
	add(Up, Up_text);
	add(Up_Key, Up_Key_text);
	add(Down, Down_text);
	add(Down_Key, Down_Key_text);
	add(Left, Left_text);
	add(Left_Key, Left_Key_text);
	add(Right, Right_text);
	add(Right_Key, Right_Key_text);
	add(Attack,Attack_text);
	add(Attack_Key, Attack_Key_text);
	add(Back, Back_text);
}

void Menu::mainmenuDrawOnScreen(RenderWindow &window, Sprite bspr)
{
	window.clear();
	window.draw(bspr);
	buttonSelect(change);
	for (int i = 0; i < amount; i++)
	{
		window.draw(drawMenu(i));
		window.draw(drawMenuText(i));
	}
	window.display();
	Sleep(100);
}

void Menu::mainmenuSelect(RenderWindow &window, Sprite bspr, Menu *setting_menu, char &a)
{

	//sterowanie wyborem przycisku strza³k¹ w dó³
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (change == amount - 1)
		{
			buttonNormal(change);
			change = 0;
		}
		else
		{
			buttonNormal(change);
			change++;
		}
		mainmenuDrawOnScreen(window, bspr);		
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up)) //sterowanie wyborem przycisku strza³k¹ w górê
	{
		if (change <= 0)
		{
			buttonNormal(0);
			change = amount - 1;
		}
		else
		{
			buttonNormal(change);
			change--;
		}
		mainmenuDrawOnScreen(window, bspr);
	}
	
	//start gry
	if (Keyboard::isKeyPressed(Keyboard::Return) && (change == 0))
	{
		SingleGame(*single) = new SingleGame(window);
		(*single).play();
		delete single;
		mainmenuDrawOnScreen(window, bspr);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Return) && (change == (amount - 2))) //widok ustawien
	{
		window.clear();
		window.draw(bspr);
		for (int i = 0; i < (*setting_menu).amountOfButtons(); i++)
		{
			window.draw((*setting_menu).drawMenu(i));
			window.draw((*setting_menu).drawMenuText(i));
		}
		window.display();
		a = 's';
		Sleep(500);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Return) && (change == amount - 1)) //zamkniecie okna enterem
	{
		delMenu();
		delTextMenu();
		(*setting_menu).delMenu();
		(*setting_menu).delTextMenu();
		delete this;
		delete setting_menu;
		window.close();
	}
}
	
void Menu::settingmenuSelect(RenderWindow &window, Sprite bspr, Menu &main_menu, char &a)
	{
				//powrót
				if (Keyboard::isKeyPressed(Keyboard::Return))
				{
					window.clear();
					window.draw(bspr);
					for (int i = 0; i < main_menu.amountOfButtons(); i++)
					{
						window.draw(main_menu.drawMenu(i));
						window.draw(main_menu.drawMenuText(i));
					}
					window.display();
					a = 'm';
					Sleep(500);
				}			
}

Sprite Menu::drawMenu(int il)
{
	return (*list_menu.at(il)).getButton();
}

Text Menu::drawMenuText(int il)
{
	return (*text_list_menu.at(il)).get_text();
}

vector<Button*> Menu::delMenu()
{
	for (int i = 0;i < amount;i++)
	{
		delete (list_menu.at(i));
	}
	return list_menu;
}

vector<Text2*> Menu::delTextMenu()
{
	for (int i = 0;i < amount;i++)
	{
		delete text_list_menu.at(i);
	}
	return text_list_menu;
}

void Menu::buttonSelect(int il)
{
	(*list_menu.at(il)).buttonSelected();
}

void Menu::buttonNormal(int il)
{
	(*list_menu.at(il)).buttonNormal();
}

Vector2f Menu::buttonPosition(int il)
{
	return ((*list_menu.at(il)).position());
}

Menu::~Menu()
{
	text_list_menu.clear();
	list_menu.clear();
}