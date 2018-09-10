#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"
#include "Text2.h"
#include "SingleGame.h"
#include <vector>
#include <windows.h>
#include <iostream>
#include <string>

#define NormalButton "Images\\Buttons\\Button.png"
#define SelectedButton "Images\\Buttons\\Button_selected.png"
#define ButtonWidth 300
#define ButtonHigh 80

using namespace sf;

class Menu
{
	int amount;
	std::vector<Button*> list_menu;
	std::vector<Text2*> text_list_menu;
	int change;
public:
	//konstruktor
	Menu(int il);
	//dodanie przycisku do menu
	void add(Button *p, Text2 *t);
	//tworzenie g³ównego menu
	void mainmenu();
	//tworzenie menu ustawieñ
	void settingmenu();
	//odczyt pozycji
	int getChange();
	//iloœæ przycisków
	int amountOfButtons();
	//wyœwietlanie obrazka przycisku
	Sprite drawMenu(int il);
	//wyœwietlanie tekstu na przycisku
	Text drawMenuText(int il);
	//usuwanie menu
	vector<Button*> delMenu();
	//usuwanie tekstow
	vector<Text2*> delTextMenu();
	//wybór przycisku - podœwietlenie
	void buttonSelect(int il);
	//anulowanie wyboru - usuniêcie podœwietlenia
	void buttonNormal(int il);
	//odczyt pozycji przycisku
	Vector2f buttonPosition(int il);
	//kontrola wyboru przycisków z g³ównego menu
	void mainmenuSelect(RenderWindow &window, Sprite bspr, Menu *setting_menu, char &a);
	//kontrola wyboru przycisków z menu ustawieñ
	void settingmenuSelect(RenderWindow &window, Sprite bspr, Menu &main_menu, char &a);
	void mainmenuDrawOnScreen(RenderWindow &window, Sprite bspr);
	//destruktor
	~Menu();
	
};