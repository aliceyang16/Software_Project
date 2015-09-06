#include <gtest/gtest.h>
#include "GameWindow.h"
#include "Player.h"

// Tests the GameWindow class for an uninitialised state. 
TEST(GameWindow, hasUninitialisedState) {
	
	GameWindow testWindow;
	testWindow.getGameWindow();
}

// Tests if player can be made.
TEST(Player, ifInvalidThrowException) {
	
	//nonExistant.png does not exist 
	EXPECT_THROW({Player testPlayer(50,50, "nonExistant.png");}, ImageCannotBeFound);
}

// Tests if player is created in the right position.
TEST(Player, ifValidDoesNotThrowException) {
	
	Player testPlayer(50,50, "resources/minion.png");
	EXPECT_EQ(50, testPlayer.x_Pos());
	EXPECT_EQ(50, testPlayer.y_Pos());
}

// Tests if player position can be set.
TEST(Player, playerPositionCanBeSet) {
	
	Player testPlayer(50,50, "resources/minion.png");
	testPlayer.setPlayer(61, 61);
	EXPECT_EQ(61, testPlayer.x_Pos());
	EXPECT_EQ(61, testPlayer.y_Pos());
}

// Tests if the player moves (if the keyboard must be used)
TEST(Player, arrowKeysNotUsedNoMovement) {
	
	Player testPlayer(50,50, "resources/minion.png");
	
	//Game is playing 
	sf::Clock clock;
	float deltaTime = clock.restart().asSeconds();
	
	EXPECT_THROW(testPlayer.movePlayer(deltaTime), NoMovement);
}
