#include <World.h>

World::World()
	: m_gravity(0.0f,0.0f),
	m_time(0.f),
	m_timestep(0.02f)
{
}

World::~World()
{
}

void World::setGravity(const sf::Vector2f Gravity)
{
	m_gravity=Gravity;
}

void World::setTimeStep(float TimeStep)
{
	m_timestep = TimeStep;
}
