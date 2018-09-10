#include "Application.h"

using namespace sf;

Application::Application():window(VideoMode(1024, 768), "Tanks Game by Daroface", Style::Default)
{
	if (!background.loadFromFile("Images\\Background\\Background.png"))
		throw 1;
	btex.loadFromImage(background);
	bspr.setTexture(btex);
}

void Application::drawMenuOnScreen(Menu actual)
{
	window.clear();
	window.draw(bspr);
	for (int i = 0; i < actual.amountOfButtons(); i++)
	{
		window.draw(actual.drawMenu(i));
		window.draw(actual.drawMenuText(i));
	}
	window.display();
}

void Application::run()
{	
	char actual = 'm';
	//tworzenie menu
	try
	{
		Menu *main_menu = new Menu(3);
		Menu *setting_menu = new Menu(11);
		(*main_menu).mainmenu();
		(*setting_menu).settingmenu();

		drawMenuOnScreen(*main_menu);

		while (window.isOpen())
		{
			Event ev;
			while (window.pollEvent(ev))
			{
				//obs³uga zmiany rozmiaru okna
				if (ev.type == Event::Resized)
				{
					if (actual == 'm')
					{
						drawMenuOnScreen(*main_menu);
					}
					else
					{
						drawMenuOnScreen(*setting_menu);
					}
				}
				//obs³uga zamkniêcia przez klikniêcie X
				if (ev.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				{
					(*main_menu).delMenu();
					(*setting_menu).delMenu();
					(*main_menu).delTextMenu();
					(*setting_menu).delTextMenu();
					delete main_menu;
					delete setting_menu;
					window.close();
				}

				if (actual == 'm')
				{
					(*main_menu).mainmenuSelect(window, bspr, setting_menu, actual);
				}
				else
				{
					(*setting_menu).settingmenuSelect(window, bspr, (*main_menu), actual);
				}
			}
		}
	}
	catch(int &e)
	{
			RenderWindow w(VideoMode(600, 300), "Error!", Style::Close);
			w.clear(Color::White);
			Text2 com("Brak pliku Images\\Buttons\\Button.png\nlub Button_selected.png", 20, 100);
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
	
}

Application::~Application()
{

}