#pragma once
#include <SFML\Graphics.hpp>

#include <GameObject.h>

class Ball : public GameObject
{
public:
	Ball(float radius = 1.f, sf::Color color = sf::Color::Green);
	~Ball();

	float setRadius(float radius);
	float getRadius();

};

