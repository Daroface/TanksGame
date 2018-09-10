#include <SFML\Graphics.hpp>
#include <windows.h>
#include "Text2.h"
#include "Application.h"



using namespace sf;



int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	try
	{
		Application App;
		App.run();
	}
	catch (int &e)
	{
		RenderWindow w(VideoMode(750, 300), "Error!", Style::Close);
		w.clear(Color::White);
		Text2 com("Brak pliku Images\\Background\\Background.png", 20, 100);
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
		exit(0);
	}
	


	return 0;
}