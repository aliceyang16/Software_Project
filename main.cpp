#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

/// \return Application exit code

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	 // Define some constants
    const int gameWidth = 800;
    const int gameHeight = 600;
	sf::Vector2f playerSize(50, 50);
	sf::Vector2f shooterSize(20,20);
	sf::Vector2f bulletScale(0.05,0.05);
	
	// Create the window of the application
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Shooter Game",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
	
	// Load the sounds used in the game
    sf::SoundBuffer shootSoundBuffer;
	if (!shootSoundBuffer.loadFromFile("resources/pewpew.wav"))
        return EXIT_FAILURE;
    sf::Sound shootSound(shootSoundBuffer);
	
	/**Load the image of the palyer*/
	sf::Texture playerImage;
	if (!playerImage.loadFromFile("resources/minion.png"))
		return EXIT_FAILURE;
		
	/** Create the player*/
	sf::Sprite player;
	player.setTexture(playerImage);
    player.setOrigin(playerSize / 2.f);
	
	/** Load the image of the shooter*/
	sf::Texture shooterImage;
	if (!shooterImage.loadFromFile("resources/banana.png"))
		return EXIT_FAILURE;
	
	sf::Sprite bullet;
	bullet.setTexture(shooterImage);
	bullet.scale(bulletScale);
	
	/** Load the text font*/
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;

    // Initialize the pause message
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(170.f, 150.f);
    pauseMessage.setColor(sf::Color::White);
    pauseMessage.setString("Welcome to Shooter!\nPress space to start the game");
	
	// Define the paddles properties
	sf::Clock AITimer;
	const sf::Time AITime   = sf::seconds(0.1f);
	const float playerSpeed = 400.f;
	const float bulletSpeed = 400.f;
	float bulletAngle = 0.f;
	
	sf::Clock clock;
	bool isPlaying = false;
	bool bulletShot = false;
	while(window.isOpen())
	{
		// Handle events
        sf::Event event;
        while (window.pollEvent(event))
		{
			// Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
			
			// Space key pressed: play
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                if (!isPlaying)
                {
                    // (re)start the game
                    isPlaying = true;
                    clock.restart();

                    // Reset the position of the player and bullet
                    player.setPosition(gameWidth / 2, gameHeight / 2);
                }
            }
		}
		
		
		
		if (isPlaying)
		{
			float deltaTime = clock.restart().asSeconds();
            // Move the player's paddle
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
               (player.getPosition().y - playerSize.y / 2 > 5.f))
            {
                player.move(0.f, -playerSpeed * deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
               (player.getPosition().y + playerSize.y / 2 < gameHeight - 5.f))
            {
                player.move(0.f, playerSpeed * deltaTime);
            }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
			   (player.getPosition().y - playerSize.y / 2 > 2.f))
			{
				player.move(playerSpeed * deltaTime,0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			   (player.getPosition().y + playerSize.y / 2 < gameWidth - 2.f))
			{
				   player.move(-playerSpeed * deltaTime,0.f);
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				bulletShot = true;
				bullet.setPosition(player.getPosition().x, player.getPosition().y);
				//bullet.setPosition(gameWidth / 2, gameHeight / 2);
			}
			
			if(bulletShot)
			{
				float factor = bulletSpeed * deltaTime;
				bullet.move(std::cos(bulletAngle) * factor, std::sin(bulletAngle) * factor);
			}
		}
		
		// Clear the window
        window.clear(sf::Color(50,50,50));

        if (isPlaying)
        {
            // Draw the paddles and the ball
            window.draw(player);
			if(bulletShot)
			{
				window.draw(bullet);
			}
        }
        else
        {
            // Draw the pause message
            window.draw(pauseMessage);
        }
		
		// Display things on screen
        window.display();
	}
	
	return EXIT_SUCCESS;
}