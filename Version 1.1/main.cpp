#include <iostream>
#include "GameWindow.h"
#include "Player.h"

int main()
{
    GameWindow testWindow;
	
	sf::Clock clock;
	
	Player minion(50,50, "resources/minion.png");
	Player evil_minion(gameWidth,gameHeight, "resources/evil_minion.png");
	
    bool isPlaying = false;
    while(testWindow.getGameWindow().isOpen())
	{
	    sf::Event event;
	    while(testWindow.getGameWindow().pollEvent(event))
		{
		    // Window closed or escape key pressed: exit
		    if((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
			    testWindow.getGameWindow().close();
			    break;
			}

		    // Space key pressed: play
		    if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
			    if(!isPlaying)
				{
				    isPlaying = true;
					clock.restart();
					minion.setPlayer(60,60);
					evil_minion.setPlayer(gameWidth/2,gameHeight/2);
				}
			}
		}
		
		if (isPlaying)
		{
			float deltaTime = clock.restart().asSeconds();
            // Move the player
			minion.movePlayer(deltaTime);
		}
		
		testWindow.getGameWindow().clear();
		
		if (isPlaying)
		{
			testWindow.drawSpriteObjects(minion.getPlayer());
			testWindow.drawSpriteObjects(evil_minion.getPlayer());
		}
		testWindow.getGameWindow().display();
	}
	
	    return 0;
}