#include <Ball.h>


//Ball::Ball()
//{
//	shape.setRadius(100.f);
//    shape.setFillColor(sf::Color::Green);
//}

Ball::Ball(float radius, sf::Color color)
{
	m_shape = new sf::CircleShape();

	setRadius(radius);

    m_shape->setFillColor(sf::Color::Green);
	m_shape->setOrigin(radius,radius);
}


Ball::~Ball()
{
}

float Ball::setRadius(float radius)
{
	((sf::CircleShape*)m_shape)->setRadius(radius*METERS_TO_PIXELS);
	UpdateSize();
	return radius;
}
float Ball::getRadius()
{
	return ((sf::CircleShape*)m_shape)->getRadius()/METERS_TO_PIXELS;
}

void Ball::PostUpdate(float dt)
{
}