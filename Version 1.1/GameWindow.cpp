///////////////////////////////////////////////////////////
//                  GameWindow
///////////////////////////////////////////////////////////

#include "GameWindow.h"

using namespace std;

GameWindow::GameWindow()
		:_gameWindow{sf::VideoMode(gameWidth, gameHeight, 32), "Shooter Game"}
{
	// Clear the window
        _gameWindow.setVerticalSyncEnabled(true);
		_gameWindow.clear(sf::Color(0,0,0));
}

void GameWindow::drawSpriteObjects(const sf::Sprite& SpriteObject)
{
	_gameWindow.draw(SpriteObject);
}

sf::RenderWindow& GameWindow::getGameWindow()
{
	return _gameWindow;
}