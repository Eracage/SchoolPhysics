#pragma once
#include <PhysicsObject.h>
#include <Collision.h>
class Collider
{
public:

	Collider(std::vector<PhysicsObject>& PhysObjects, sf::Rect<float>& WorldLimits, float sleepVelocity);
	~Collider();

	void Update();

	// Make world iterate collisions multiple times without objects really moving
	void setIterationCount(unsigned int CollisionIterations);



	
private:
	Collider(Collider&);
	Collider& operator=(Collider&);
	// resize vector if needed
	void ReserveCollisionSpace();
	// collide objects with wall
	void ApplyWallCollision();
	// check if balls have collisions with each other
	bool SolveBallCollisions();
	// really collide the object having collisions
	void SolveBall(const int index);
	// Check if balls touch
	void BasicBallCollision(const int a, const int b);
	bool AABB(const PhysicsObject& A, const PhysicsObject& B) const;

	sf::Rect<float>& m_worldLimits;
	std::vector<PhysicsObject>& m_physObjects;
	unsigned int m_iters;
	std::vector<std::vector<Collision>> m_collisions;
	unsigned int m_reservedSpace;
	float m_sleepV;
};

