#include <Collider.h>

//bool Collider::CheckCollision(const GameObject &fo, const GameObject &so, const CollisionQuality quality)
//{
//	if (BasicBallCollision(fo,so))
//	{
//		return true;
//	}
//	return false;
//}

bool Collider::ApplyPhysics(GameObject &fo, GameObject &so, const CollisionQuality quality)
{
	const sf::Vector2f difVector = (so.M_Position-fo.M_Position);

	if (BasicBallCollision(fo,so))
	{
		switch (quality)
		{
			case BASIC_BALL:
				break;
			case DEFAULT:
				break;
			case ADVANCED:
				break;
		}
		return true;
	}
	return false;
}

bool Collider::BasicBallCollision(const GameObject &fo, const GameObject &so)
{
	const float soRadiusP2 = so.M_Radius_Pow2;
	const sf::Vector2f difVector = (so.M_Position-fo.M_Position);
	const float foRadiusP2 = fo.M_Radius_Pow2;

	if (pow(difVector.x,2) + pow(difVector.y,2) <
		foRadiusP2 + soRadiusP2)
	{
		return true;
	}
	return false;
}

bool Collider::AdvancedCollision(const GameObject &firstObject, const GameObject &secondObject);
