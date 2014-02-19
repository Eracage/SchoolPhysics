#pragma once
#include <SFML\Graphics.hpp>
class Ball
{
public:
	//Ball();
	Ball(float radius = 100.f, sf::Color color = sf::Color::Green);
	~Ball();

	void Update(float dt);
	void setConstantForce(sf::Vector2f force);

	sf::Vector2f force;
	sf::Vector2f velocity;

	sf::CircleShape shape;
};

