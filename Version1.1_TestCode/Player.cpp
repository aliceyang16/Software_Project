/////////////////////////////////////////////////////////////////
//                           Player
////////////////////////////////////////////////////////////////
#include "Player.h"

Player::Player(float x, float y, string file_location)
	  :x_position{x}, y_position{y}
{
	if (!_image.loadFromFile(file_location))
	{
		throw ImageCannotBeFound();
	}
	
	_player.setTexture(_image);
	_player.setOrigin(50 / 2.f , 50/ 2.f );
}

void Player::setPlayer(const float& x, const float& y)
{
	x_position = x;
	y_position = y;
	
	_player.setPosition(x, y);
}

void Player::movePlayer(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
               (_player.getPosition().y - playerSize_y / 2 > 5.f))
	{
		_player.move(0.f, -playerSpeed * deltaTime);
		//setPlayer(0, -playerSpeed * deltaTime);
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
               (_player.getPosition().y + playerSize_y / 2 < gameHeight - 2.f))
	{
		_player.move(0.f, playerSpeed * deltaTime);
		//setPlayer(0, playerSpeed * deltaTime);
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) /*&&
			   (_player.getPosition().y - playerSize_y / 2 > 2.f)*/)
	{
		_player.move(playerSpeed * deltaTime,0.f);
		//setPlayer(playerSpeed * deltaTime,0);
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			   (_player.getPosition().y + playerSize_y / 2 < gameWidth - 2.f))
	{
		_player.move(-playerSpeed * deltaTime,0.f);
		//setPlayer(-playerSpeed * deltaTime,0);
	}
	
	//Throw an exception if their is no movement 
		throw NoMovement();
}

sf::Sprite& Player::getPlayer()
{
	return _player;
}

float& Player::x_Pos()
{
	return x_position;
}

float& Player::y_Pos()
{
	return y_position;
}