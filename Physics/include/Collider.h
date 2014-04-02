#pragma once
#include <GameObject.h>
#include <Collision.h>
class Collider
{
private:
	Collider(){}
	~Collider(){}
public:
	enum CollisionQuality
	{
		BASIC_BALL,
		DEFAULT,
		ADVANCED
	};

	//static bool CheckCollision(const GameObject &firstObject, const GameObject &secondObject, const CollisionQuality quality);
	
	static bool ApplyPhysics(GameObject &firstObject, GameObject &secondObject, const CollisionQuality quality);
	
	static bool BasicBallCollision(const GameObject &firstObject, const GameObject &secondObject);

	static bool AdvancedCollision(const GameObject &firstObject, const GameObject &secondObject);
};

