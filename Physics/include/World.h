#pragma once
#include <SFML\System\Vector2.hpp>
#include <GameObject.h>
#include <vector>

class World
{
public:
	World();
	~World();
	void setGravity(sf::Vector2f Gravity);
	void setTimeStep(float TimeStep);
private:
	std::vector<GameObject*> m_gameObjects;
	sf::Vector2f m_gravity;
	float m_time;
	float m_timestep;
};
