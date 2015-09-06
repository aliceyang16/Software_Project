#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameWindow.h"

using namespace std;

const float playerSpeed = 400.f;
const float playerSize_y = 50;
const float palyerSize_x = 50;

class ImageCannotBeFound {};

class Player
{
public:
	//Constructor
	Player(float x, float y, string file_location);

	sf::Sprite& getPlayer();
	void setPlayer(const float& x, const float& y);
	void movePlayer(const float& deltaTime);
	float& y_Pos();
	float& x_Pos();
	
private:
	sf::Sprite _player;
	sf::Texture _image;
	
	float x_position;
	float y_position;
};

#endif