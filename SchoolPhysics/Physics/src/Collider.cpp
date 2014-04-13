#include <Collider.h>
#include <DebugTimer.h>

const float Dot(const sf::Vector2f a, const sf::Vector2f b)
{
	return a.x * b.x + b.y * a.y;
}
const int sign(const float value)
{
	return (0.f<value)-(value<0.f);
}

Collider::Collider(std::vector<PhysicsObject>& PhysObjects, sf::Rect<float>& WorldLimits, float sleepVelocity)
	: m_physObjects(PhysObjects),
	m_worldLimits(WorldLimits),
	m_iters(1),
	m_reservedSpace(0),
	m_sleepV(sleepVelocity)
{}
Collider::~Collider()
{}

void Collider::Update()
{
	ReserveCollisionSpace();
	
	for (int a = static_cast<int>(m_physObjects.size()) - 1; a >= 0; --a)
	{
		m_physObjects[a].M_StaticCollision = static_cast<unsigned int>(-1);
	}

	for (unsigned int iters = 0; iters <= m_iters; ++iters)
	{
		if (iters%2 == 0)
		{
			for (int a = 0; a < static_cast<int>(m_physObjects.size()); ++a)
			{
				for (int b = a+1; b < static_cast<int>(m_physObjects.size()); ++b)
				{
					BasicBallCollision(a, b);
				}
			}
			// returns if no collisions happened, so no need to iterate any further
			if (SolveBallCollisions())
			{
				ApplyWallCollision();
				return;
			}
		}
		else
		{
			for (int a = static_cast<int>(m_physObjects.size())-1; a > -1; --a)
			{
				for (int b = a-1; b > -1; --b)
				{
					BasicBallCollision(a, b);
				}
			}
			// returns if no collisions happened, so no need to iterate any further
			if (SolveBallCollisions())
			{
				ApplyWallCollision();
				return;
			}
		}
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
		m_collisions.resize(m_physObjects.size(),std::vector<Collision>());
		for (size_t i = 0; i < m_collisions.size(); i++)
		{
			m_collisions[i].reserve(10);
		}
	}
}
void Collider::ApplyWallCollision()
{
	// go through all objects
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

		bool staticCol = false;

		if (Wleft>Aleft) // check against borders
		{
			staticCol = true;
			if (A.M_Velocity.x < 0)
				A.M_Velocity.x *= -A.M_Bounciness;
			A.M_Position.x += Wleft-Aleft;
			//friction
			const float friction = A.M_Friction * abs(A.M_Velocity.x);
			const float newVel = A.M_Velocity.y - friction * sign(A.M_Velocity.y);
			A.M_Velocity.y = sign(A.M_Velocity.y) == sign(newVel) ? newVel : 0.f;
		}
		if (Wright<Aright) // check against borders
		{
			staticCol = true;
			if (A.M_Velocity.x > 0)
				A.M_Velocity.x *= -A.M_Bounciness;
			A.M_Position.x += Wright-Aright;
			//friction
			const float friction = A.M_Friction * abs(A.M_Velocity.x);
			const float newVel = A.M_Velocity.y - friction * sign(A.M_Velocity.y);
			A.M_Velocity.y = sign(A.M_Velocity.y) == sign(newVel) ? newVel : 0.f;
		}
		if (Wtop<Atop) // check against borders
		{
			staticCol = true;
			if (A.M_Velocity.y > 0)
				A.M_Velocity.y *= -A.M_Bounciness;
			A.M_Position.y += Wtop-Atop;
			//friction
			const float friction = A.M_Friction * abs(A.M_Velocity.y);
			const float newVel = A.M_Velocity.x - friction * sign(A.M_Velocity.x);
			A.M_Velocity.x = sign(A.M_Velocity.x) == sign(newVel) ? newVel : 0.f;
		}
		if (Wbot>Abot) // check against borders
		{
			staticCol = true;
			if (A.M_Velocity.y < 0)
				A.M_Velocity.y *= -A.M_Bounciness;
			A.M_Position.y += Wbot-Abot;
			//friction
			const float friction = A.M_Friction * abs(A.M_Velocity.y);
			const float newVel = A.M_Velocity.x - friction * sign(A.M_Velocity.x);
			A.M_Velocity.x = sign(A.M_Velocity.x) == sign(newVel) ? newVel : 0.f;
		}
		if (staticCol)
			A.M_StaticCollision = 0;
	}
}
bool Collider::SolveBallCollisions()
{
	bool retVal = true;
	
	// go through objects, and check if they have collided with something
	for (size_t i = 0; i < m_physObjects.size(); i++)
	{
		if (!m_collisions[i].empty())
		{
			retVal = false;

			SolveBall(i);

			m_collisions[i].clear();
		}
	}
	// returns if no collisions happened, so no need to iterate any further
	return retVal;
}
void Collider::SolveBall(const int index)
{
	std::vector<Collision>& colVec = m_collisions[index];
			
	const int collisions = colVec.size();
	const float weight1Col = 1.f / collisions;

	const PhysicsObject* A = colVec[0].A;
	const sf::Vector2f Apos = A->M_Position;
			
	sf::Vector2f oVel = colVec[0].Av;

	//for (int iters = 0; iters < collisions; iters++)
	//{
		// copy velocity to use in iteration
		const sf::Vector2f iVel = oVel; 

		for (int i = 0; i < collisions; i++)
		{
			const sf::Vector2f A_B = colVec[i].A_B;
			const float A_B_Length = sqrt(Dot(colVec[i].A_B,colVec[i].A_B));

			//static collision objects don't "squish" when under pressure
			const unsigned int Astatic = A->M_StaticCollision;
			const unsigned int Bstatic = colVec[i].B->M_StaticCollision;

			float pushValue;
			if (Astatic == Bstatic)
				pushValue = 0.5f;
			//else if (Astatic < Bstatic)
			//{
			//	pushValue = 0.9f;
			//	colVec[i].B->M_StaticCollision = Astatic+1;
			//}
			//else
			//{
			//	pushValue = 0.1f;
			//	colVec[i].A->M_StaticCollision = Bstatic+1;
			//}


			const sf::Vector2f givenVel = Dot(iVel,A_B)/Dot(A_B,A_B)*A_B * weight1Col;
			colVec[i].B->M_Velocity += givenVel;
			oVel -= givenVel;

			colVec[i].B->M_Position += A_B*(pushValue*(colVec[i].combRad-A_B_Length)/A_B_Length);
		}
	//}


	colVec[0].A->M_Velocity += oVel-colVec[0].Av;
}
void Collider::BasicBallCollision(const int a, const int b)
{
	const PhysicsObject& B = m_physObjects[b];
	const PhysicsObject& A = m_physObjects[a];

	if (!AABB(A,B))
		return;
	

	const float bRadius = B.M_Radius;
	const sf::Vector2f difVector = (B.M_Position-A.M_Position);
	const float aRadius = A.M_Radius;
	const float difVecLengthPow2 = Dot(difVector,difVector);
	const float combRad = aRadius + bRadius;
	const float combRadP2 = combRad*combRad;
	if (difVecLengthPow2 < combRadP2)
	{
		m_collisions[a].push_back(Collision(&m_physObjects[a],&m_physObjects[b], combRad));
		m_collisions[b].push_back(Collision(&m_physObjects[b],&m_physObjects[a], combRad));
	}
}

bool Collider::AABB(const PhysicsObject& A, const PhysicsObject& B) const
{
	const float Ap[3] = {A.M_Position.x,A.M_Position.y, A.M_Radius};
	const float Bp[3] = {B.M_Position.x,B.M_Position.y, B.M_Radius};

	if (Ap[0]+Ap[2] < Bp[0] - Bp[2])
		return false;
	if (Ap[0]-Ap[2] > Bp[0] + Bp[2])
		return false;
	if (Ap[1]+Ap[2] < Bp[1] - Bp[2])
		return false;
	if (Ap[1]-Ap[2] > Bp[1] + Bp[2])
		return false;

	return true;
}
