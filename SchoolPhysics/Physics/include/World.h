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

	// set global gravity
	void setGravity(sf::Vector2f Gravity);
	// set timestep for update
	void setTimeStep(float TimeStep);
	// set collision iteration count, more is better but takes more time
	void setIterationCount(unsigned int CollisionIterations = 4);
	// toggles approximate update function so items would move smoother
	void toggleApproxUpdate(bool value = false);
	// sets the global world size, nothing can go out of these bounds
	void setWorldSize(sf::Vector2f WorldSize_Meters = sf::Vector2f(40.f,30.f));
	// copies physical object to world
	int addToWorld(PhysicsObject Object);
	// returns reference to object in world
	PhysicsObject& accessObject(int ID);
	// counts objects (balls) in world
	int ballCount();

	// updates the world, counting from dt when to make timesteps
	// returns 0 if approx/idle call, 1 if advanced 1 timestep, > 1 if could not keep up 
	int Update(float dt);
	// draws the world, and all the objects inside
	void Draw(sf::RenderWindow &window);

	void setWorldBackGroundColor(sf::Color Background = sf::Color::Black);
	void setWorldBorder(sf::Color Borders = sf::Color::White, float BorderThickness_Pixels = 10);

	// returns mouse position in the world
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
