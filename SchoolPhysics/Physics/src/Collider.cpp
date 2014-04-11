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
		ApplyWallCollision();
		for (size_t a = 0; a < m_physObjects.size(); ++a)
		{
			for (size_t b = a+1; b < m_physObjects.size(); ++b)
			{

			}
		}
		SolveBallCollisions();
	}
	
	ApplyWallCollision();
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
	for (size_t a = 0; a < m_physObjects.size(); ++a)
	{
		PhysicsObject& A = m_physObjects[a];
		const sf::Rect<float> WL = m_worldLimits;
		const sf::Vector2f Apos = A.M_Position;
		const float Arad = A.M_Radius;
		const float Aleft = Apos.x - Arad;
		const float Aright = Apos.x + Arad;
		const float Atop = Apos.y + Arad;
		const float Abot = Apos.y - Arad;
		const float Wleft = WL.left;
		const float Wright = WL.left+WL.width;
		const float Wtop = WL.top;
		const float Wbot = WL.top-WL.height;

		if (Wleft>Aleft)
		{
			if (A.M_Velocity.x < 0)
				A.M_Velocity.x *= -A.M_Bounciness;
			A.M_Position.x += Wleft-Aleft;
		}
		if (Wright<Aright)
		{
			if (A.M_Velocity.x > 0)
				A.M_Velocity.x *= -A.M_Bounciness;
			A.M_Position.x += Wright-Aright;
		}
		if (Wtop<Atop)
		{
			if (A.M_Velocity.y > 0)
				A.M_Velocity.y *= -A.M_Bounciness;
			A.M_Position.y += Wtop-Atop;
		}
		if (Wbot>Abot)
		{
			if (A.M_Velocity.y < 0)
				A.M_Velocity.y *= -A.M_Bounciness;
			A.M_Position.y += Wbot-Abot;
		}

	}
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
	const PhysicsObject& A = m_physObjects[a];
	const PhysicsObject& B = m_physObjects[b];

	const float soRadiusP2 = B.M_Radius_Pow2;
	const sf::Vector2f difVector = (B.M_Position-A.M_Position);
	const float foRadiusP2 = A.M_Radius_Pow2;
	const float difVecLengthPow2 = Dot(difVector,difVector);
	const float combRad = foRadiusP2 + soRadiusP2;

	if (difVecLengthPow2 < combRad)
	{
		m_collisions[a].push_back(Collision(&m_physObjects[a],&m_physObjects[b]));
	}
	return false;
}
