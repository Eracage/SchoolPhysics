#include <Collider.h>

//bool Collider::CheckCollision(const GameObject &fo, const GameObject &so, const CollisionQuality quality)
//{
//	if (BasicBallCollision(fo,so))
//	{
//		return true;
//	}
//	return false;
//}

void Collider::Update()
{
	for (unsigned int iters = 0; iters <= m_iters; ++iters)
	{
		for (size_t a = 0; a < m_physObjects.size(); ++a)
		{
			for (size_t b = a+1; b < m_physObjects.size(); ++b)
			{

			}
		}
	}
	
	for (size_t a = 0; a < m_physObjects.size(); ++a)
	{

	}
}
void Collider::setIterationCount(unsigned int CollisionIterations)
{
	m_iters = CollisionIterations;
}

bool Collider::ApplyPhysics(PhysicsObject &fo, PhysicsObject &so, const CollisionQuality quality)
{
	return ApplyPhysics(fo, so, static_cast<int>(quality));
}
bool Collider::ApplyPhysics(PhysicsObject &fo, PhysicsObject &so, int quality)
{
	//const sf::Vector2f difVector = (so.M_Position-fo.M_Position);

	//while (quality > 0)
	//{
	//	if (quality&BASIC_SQUARE)
	//	{
	//		if (!BasicSquareCollision(fo,so))
	//			return false;
	//		quality=quality^BASIC_SQUARE;
	//	}
	//	else if (quality&BASIC_BALL)
	//	{
	//		if (!BasicBallCollision(fo,so))
	//			return false;
	//		quality-=BASIC_BALL;
	//	}
	//}

	//if (quality&BASIC_BALL)
	//{
	//	switch (quality)
	//	{
	//		case BASIC_BALL:
	//			break;
	//		case DEFAULT:
	//			break;
	//		case ADVANCED:
	//			break;
	//	}
	//	return true;
	//}
	//return false;
	return false;
}

bool Collider::checkCollision(PhysicsObject &firstObject, PhysicsObject &secondObject, const int quality)
{
	return false;
}
bool Collider::BasicBallCollision(const PhysicsObject &fo, const PhysicsObject &so)
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
bool Collider::BasicSquareCollision(const PhysicsObject &fo, const PhysicsObject &so)
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

bool Collider::AdvancedCollision(const PhysicsObject &firstObject, const PhysicsObject &secondObject)
{
	return false;
}
