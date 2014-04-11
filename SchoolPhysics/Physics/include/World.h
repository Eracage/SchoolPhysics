#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <PhysicsObject.h>
#include <Collider.h>

const static float METERS_TO_PIXELS = 50;
const static float GROUND_Y_IN_PIXELS = 700;
const static float GROUND_MIDX_IN_PIXELS = 640;

class World
{
public:
	World();
	~World();
	void setGravity(sf::Vector2f Gravity);
	void setTimeStep(float TimeStep);
	void setIterationCount(unsigned int CollisionIterations = 4);
	void toggleApproxUpdate(bool value = false);
	void setWorldSize(sf::Vector2f WorldSize_Meters = sf::Vector2f(22.f,13.f));

	void addToWorld(PhysicsObject Object);

	void Update(float dt);
	void Draw(sf::RenderWindow &window);

	void setWorldBackGroundColor(sf::Color Background = sf::Color::Black);
	void setWorldBorder(sf::Color Borders = sf::Color::White, float BorderThickness_Pixels = 10);


private:

	sf::Vector2f m_gravity;
	float m_time;
	float m_timestep;
	unsigned int m_colItCount;
	bool m_approxUpdate;
	sf::Rect<float> m_worldLimits;
	sf::RectangleShape m_worldRect;
	std::vector<PhysicsObject> m_physObjects;
	Collider m_collider;
};
