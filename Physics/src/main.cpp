#include <SFML/Graphics.hpp>
#include <SceneHandler.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	sf::Clock clock;
	sf::CircleShape asdf;
	float dt = 0.01f;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		dt = (clock.restart()).asSeconds();
		SceneHandler::update(dt);

        window.clear();
		SceneHandler::draw(window);
        window.display();
    }

    return 0;
}