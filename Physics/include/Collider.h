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
		BASIC_SQUARE	= 1<<0,
		BASIC_BALL	= 1<<1
		ADVANCED
	};

	//static bool CheckCollision(const GameObject &firstObject, const GameObject &secondObject, const CollisionQuality quality);
	//static bool AddGameObject(GameObject
	static bool ApplyPhysics(GameObject &firstObject, GameObject &secondObject, const CollisionQuality quality);
	static bool ApplyPhysics(GameObject &firstObject, GameObject &secondObject, const int quality);
	
private:
	static bool checkCollision(GameObject &firstObject, GameObject &secondObject, const int quality);
	static bool BasicBallCollision(const GameObject &firstObject, const GameObject &secondObject);
	static bool BasicSquareCollision(const GameObject &firstObject, const GameObject &secondObject);
	static bool AdvancedCollision(const GameObject &firstObject, const GameObject &secondObject);
};

