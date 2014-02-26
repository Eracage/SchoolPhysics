#include "Ball.h"


//Ball::Ball()
//{
//	shape.setRadius(100.f);
//    shape.setFillColor(sf::Color::Green);
//}

Ball::Ball(float radius, sf::Color color)
{
	m_shape = new sf::CircleShape();
	setRadius(radius);
	M_Shape = CIRCLE;

    shape.setFillColor(sf::Color::Green);
	shape.setOrigin(radius,radius);
}


Ball::~Ball()
{
}

float Ball::setRadius(float radius)
{
	((sf::CircleShape*)m_shape)->setRadius(radius);
	UpdateSize();
	return radius;
}
float Ball::getRadius()
{
	return ((sf::CircleShape*)m_shape)->getRadius();
}

void Ball::PostUpdate(float dt)
{
}