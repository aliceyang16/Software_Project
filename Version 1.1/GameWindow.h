#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
/////////////////////////////////////////////////////////////////////////
//! screen displays the screen used in for the game
/*! 
	\author Alice Yang
	\author Peter Cotzee
	\version 2.0
	\date 5 September 2015
*/

using namespace std;

const int gameWidth = 800;	/*! variable storing the width of the screen*/
const int gameHeight = 600;	/*! variable storing the height of the screen*/

class GameWindow
{
public:
	GameWindow();
	void drawSpriteObjects(const sf::Sprite& SpriteObject);
	sf::RenderWindow& getGameWindow();
	
private:
	sf::RenderWindow _gameWindow;
	sf::Text welcomeText;
	sf::Font welcomeFont;
};

#endif