#include <World.h>

World::World()
	: m_gravity(0.0f,0.0f),
	m_time(0.f),
	m_timestep(0.02f),
	m_collider(m_physObjects, m_worldLimits)
{
	setWorldSize();
	setWorldBackGroundColor();
	setWorldBorder();
	setIterationCount();
	toggleApproxUpdate();
	m_physObjects.reserve(1000);
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

void World::setIterationCount(unsigned int CollisionIterations)
{
	m_colItCount = CollisionIterations;
	m_collider.setIterationCount(m_colItCount);
}

void World::toggleApproxUpdate(bool value)
{
	m_approxUpdate = value;
}

void World::setWorldSize(sf::Vector2f size)
{
	m_worldLimits = sf::Rect<float>(
		GROUND_MIDX_IN_PIXELS/METERS_TO_PIXELS-size.x/2.f,
		GROUND_Y_IN_PIXELS/METERS_TO_PIXELS-size.y,
		size.x,
		size.y);
	m_worldRect.setPosition(
		m_worldLimits.left * METERS_TO_PIXELS, 
		m_worldLimits.top * METERS_TO_PIXELS);
	m_worldRect.setSize(sf::Vector2f(
		m_worldLimits.width*METERS_TO_PIXELS, 
		m_worldLimits.height*METERS_TO_PIXELS));
}

void World::addToWorld(PhysicsObject Object)
{
	m_physObjects.push_back(Object);
}

void World::Update(float dt)
{
	m_time+=dt;
	if (m_time > m_timestep)
	{
		m_time = 0.f;
		for (auto obj = m_physObjects.begin(); obj != m_physObjects.end(); ++obj)
		{
			(*obj).PreColUpdate(m_timestep, m_gravity);
		}
		m_collider.Update();
		for (auto obj = m_physObjects.begin(); obj != m_physObjects.end(); ++obj)
		{
			(*obj).PostColUpdate(m_timestep, m_gravity);
		}
	}
	else
	{
		if (m_approxUpdate)
		{
			for (auto obj = m_physObjects.begin(); obj != m_physObjects.end(); ++obj)
			{
				(*obj).ApproxUpdate(m_time, m_gravity);
			}
		}
	}
}

void World::Draw(sf::RenderWindow &window)
{
	window.draw(m_worldRect);
	for (auto obj = m_physObjects.begin(); obj != m_physObjects.end(); ++obj)
	{
		(*obj).Draw(window);
	}
}

void World::setWorldBackGroundColor(sf::Color Background)
{
	m_worldRect.setFillColor(Background);
}
void World::setWorldBorder(sf::Color Borders, float BorderThickness_Pixels)
{
	m_worldRect.setOutlineThickness(BorderThickness_Pixels);
	m_worldRect.setOutlineColor(Borders);
}