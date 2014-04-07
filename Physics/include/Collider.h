#pragma once
#include <GameObject.h>
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
		BASIC_SQUARE	= 1<<0,
		BASIC_BALL		= 1<<1
	};

	//static bool CheckCollision(const GameObject &firstObject, const GameObject &secondObject, const CollisionQuality quality);
	//static bool AddGameObject(GameObject
	static bool ApplyPhysics(GameObject &firstObject, GameObject &secondObject, const CollisionQuality quality);
	static bool ApplyPhysics(GameObject &firstObject, GameObject &secondObject, const int quality);

private:
	static bool checkCollision(GameObject &firstObject, GameObject &secondObject, const int quality);
	static bool BasicBallCollision(const GameObject &firstObject, const GameObject &secondObject);
	static bool BasicSquareCollision(const GameObject &firstObject, const GameObject &secondObject);
};

