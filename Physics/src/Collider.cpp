#include <Collider.h>

float Dot(const sf::Vector2f a, const sf::Vector2f b)
{
	return a.x * b.x + b.y * a.y;
}

Collider::Collider(std::vector<PhysicsObject>& PhysObjects, sf::Rect<float>& WorldLimits)
	: m_physObjects(PhysObjects),
	m_worldLimits(WorldLimits),
	m_iters(1),
	m_reservedSpace(0)
{}

Collider::~Collider()
{}

void Collider::Update()
{
	ReserveCollisionSpace();
	for (unsigned int iters = 0; iters <= m_iters; ++iters)
	{
		for (size_t a = 0; a < m_physObjects.size(); ++a)
		{
			ApplyWallCollision();
			for (size_t b = a+1; b < m_physObjects.size(); ++b)
			{

			}
		}
		SolveBallCollisions();
	}
	
	for (size_t a = 0; a < m_physObjects.size(); ++a)
	{
		ApplyWallCollision();
	}
}
void Collider::setIterationCount(unsigned int CollisionIterations)
{
	m_iters = CollisionIterations;
}

void Collider::ReserveCollisionSpace()
{
	if (m_reservedSpace < m_physObjects.size())
	{
		m_collisions.resize(m_physObjects.size());
	}
}

void Collider::ApplyWallCollision()
{
	//const float ax = fo.M_Position.x;
	//const float ay = fo.M_Position.y;
	//const float l = fo.M_Radius_Pow2 + so.M_Radius_Pow2;;
	//const float bx = so.M_Position.x;
	//const float by = so.M_Position.y;
	//if (abs(ax-bx)>l)
	//	return false;
	//if (abs(ay-by)>l)
	//	return false;
	//return true;
}

void Collider::SolveBallCollisions()
{
	for (size_t i = 0; i < m_physObjects.size(); i++)
	{
		if (!m_collisions[i].empty())
		{

		}
	}
}

bool Collider::BasicBallCollision(const size_t a, const size_t b)
{
	const float soRadiusP2 = m_physObjects[b].M_Radius_Pow2;
	const sf::Vector2f difVector = (m_physObjects[b].M_Position-m_physObjects[a].M_Position);
	const float foRadiusP2 = m_physObjects[a].M_Radius_Pow2;
	const float difVecLengthPow2 = Dot(difVector,difVector);
	const float combRad = foRadiusP2 + soRadiusP2;

	if (difVecLengthPow2 < combRad)
	{
		m_collisions[a].push_back(Collision(m_physObjects[a],m_physObjects[b]));
	}
	return false;
}
