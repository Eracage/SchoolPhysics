#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <PhysicsObject.h>
#include <Collider.h>

static float METERS_TO_PIXELS = 20;
const static float GROUND_Y_IN_PIXELS = 700;
const static float GROUND_MIDX_IN_PIXELS = 860;

class World
{
public:
	World();
	~World();
	void setGravity(sf::Vector2f Gravity);
	void setTimeStep(float TimeStep);
	void setIterationCount(unsigned int CollisionIterations = 4);
	void toggleApproxUpdate(bool value = false);
	void setWorldSize(sf::Vector2f WorldSize_Meters = sf::Vector2f(40.f,30.f));

	int addToWorld(PhysicsObject Object);
	PhysicsObject& accessObject(int ID);

	int ballCount();
	void Update(float dt);
	void Draw(sf::RenderWindow &window);

	void setWorldBackGroundColor(sf::Color Background = sf::Color::Black);
	void setWorldBorder(sf::Color Borders = sf::Color::White, float BorderThickness_Pixels = 10);

	sf::Vector2f getMousePositionInWorld(sf::RenderWindow &window);


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
