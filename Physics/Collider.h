#pragma once
#include "GameObject.h"
class Collider
{
private:
	Collider(){}
	~Collider(){}
	struct Collision
	{
		bool collided;
	};
public:
	enum CollisionQuality
	{
		BASIC_BALL
	};

	//static bool CheckCollision(const GameObject &firstObject, const GameObject &secondObject, const CollisionQuality quality);
	
	static bool ApplyPhysics(GameObject &firstObject, GameObject &secondObject, const CollisionQuality quality);

	static bool BasicBallCollision(const GameObject &firstObject, const GameObject &secondObject);
};

