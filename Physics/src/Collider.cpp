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
	return ApplyPhysics(fo, so, static_cast<int>(quality));
}
bool Collider::ApplyPhysics(GameObject &fo, GameObject &so, int quality)
{
	const sf::Vector2f difVector = (so.M_Position-fo.M_Position);

	while (quality > 0)
	{
		if (quality&BASIC_SQUARE)
		{
			if (!BasicSquareCollision(fo,so))
				return false;
			quality=quality^BASIC_SQUARE;
		}
		else if (quality&BASIC_BALL)
		{
			if (!BasicBallCollision(fo,so))
				return false;
			quality-=BASIC_BALL;
		}
	}

	if (quality&BASIC_BALL)
	{
		return true;
	}
	return false;
}

bool Collider::checkCollision(GameObject &firstObject, GameObject &secondObject, const int quality)
{
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
bool Collider::BasicSquareCollision(const GameObject &fo, const GameObject &so)
{
	const float ax = fo.M_Position.x;
	const float ay = fo.M_Position.y;
	const float l = fo.M_Radius_Pow2 + so.M_Radius_Pow2;;
	const float bx = so.M_Position.x;
	const float by = so.M_Position.y;
	if (abs(ax-bx)>l)
		return false;
	if (abs(ay-by)>l)
		return false;
	return true;
}
