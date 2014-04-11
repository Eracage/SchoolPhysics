#pragma once
#include <PhysicsObject.h>
#include <Collision.h>
class Collider
{
public:

	Collider(std::vector<PhysicsObject>& PhysObjects, sf::Rect<float>& WorldLimits)
		: m_physObjects(PhysObjects),
		m_worldLimits(WorldLimits)
	{}
	~Collider(){}

	enum CollisionQuality
	{
		BASIC_SQUARE	= 1<<0,
		BASIC_BALL		= 1<<1,
		ADVANCED		= 1<<2
	};

	void Update();
	void setIterationCount(unsigned int CollisionIterations);

	//static bool CheckCollision(const GameObject &firstObject, const GameObject &secondObject, const CollisionQuality quality);
	//static bool AddGameObject(GameObject
	static bool ApplyPhysics(PhysicsObject &firstObject, PhysicsObject &secondObject, const CollisionQuality quality);
	static bool ApplyPhysics(PhysicsObject &firstObject, PhysicsObject &secondObject, const int quality);
	
private:
	static bool checkCollision(PhysicsObject &firstObject, PhysicsObject &secondObject, const int quality);
	static bool BasicBallCollision(const PhysicsObject &firstObject, const PhysicsObject &secondObject);
	static bool BasicSquareCollision(const PhysicsObject &firstObject, const PhysicsObject &secondObject);
	static bool AdvancedCollision(const PhysicsObject &firstObject, const PhysicsObject &secondObject);

	sf::Rect<float>& m_worldLimits;
	std::vector<PhysicsObject>& m_physObjects;
	unsigned int m_iters;
};

