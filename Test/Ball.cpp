#include "Ball.h"


//Ball::Ball()
//{
//	shape.setRadius(100.f);
//    shape.setFillColor(sf::Color::Green);
//}

Ball::Ball(float radius, sf::Color color)
	: velocity(0,0),
	  force(0,0)
{
	shape.setRadius(radius);
    shape.setFillColor(sf::Color::Green);
	shape.setOrigin(radius,radius);
}


Ball::~Ball()
{
}

void Ball::Update(float dt)
{
	velocity += force*(float)dt;
	shape.setPosition(shape.getPosition()+velocity);
}


void Ball::setConstantForce(sf::Vector2f force)
{
	this->force = force;
}
