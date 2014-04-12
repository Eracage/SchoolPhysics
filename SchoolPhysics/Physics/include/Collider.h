#pragma once
#include <PhysicsObject.h>
#include <Collision.h>
class Collider
{
public:

	Collider(std::vector<PhysicsObject>& PhysObjects, sf::Rect<float>& WorldLimits, float sleepVelocity);
	~Collider();

	enum CollisionQuality
	{
		BASIC_SQUARE	= 1<<0,
		BASIC_BALL		= 1<<1,
		ADVANCED		= 1<<2
	};

	void Update();

	void setIterationCount(unsigned int CollisionIterations);



	
private:
	void ReserveCollisionSpace();
	void ApplyWallCollision();
	bool SolveBallCollisions();
	void SolveBall(const size_t index);
	bool BasicBallCollision(const size_t a, const size_t b);

	const sf::Rect<float>& m_worldLimits;
	std::vector<PhysicsObject>& m_physObjects;
	unsigned int m_iters;
	std::vector<std::vector<Collision>> m_collisions;
	unsigned int m_reservedSpace;
	float m_sleepV;
};

