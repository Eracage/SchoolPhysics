#include <SFML/Graphics.hpp>
#include <SceneHandler.h>

int main()
{
	srand(time(0));
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Physics by Esko Haila");

	sf::Clock clock;
	float dt = 0.01f;

	std::string publicText("Switch scene with F buttons");
	publicText.append("\nF1 Basic Ball scene");
	publicText.append("\nF2 Ball collision scene (no gravity)");
	publicText.append("\nF3 Lots of balls");
	publicText.append("\nF4 Ball throwing scene");
	Scene::setPublicText(publicText);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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