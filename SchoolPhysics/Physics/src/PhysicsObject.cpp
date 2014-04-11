#include <PhysicsObject.h>
#include <World.h>

PhysicsObject::PhysicsObject()
	: M_Velocity(0,0),
	  M_ConstantForce(0,0),
	  M_Position(0,0),
	  M_Bounciness(0.95),
	  m_shape(nullptr)
{}


PhysicsObject::~PhysicsObject()
{}


void PhysicsObject::PreColUpdate(float timestep, const sf::Vector2f& gravity)
{
	M_Velocity+=(M_ConstantForce + gravity) * timestep * 0.5f;
	M_Position+=M_Velocity * timestep;
}
void PhysicsObject::PostColUpdate(float timestep, const sf::Vector2f& gravity)
{
	M_Velocity+=(M_ConstantForce + gravity) * timestep * 0.5f;

	setShapePos();
}
void PhysicsObject::ApproxUpdate(float time, const sf::Vector2f& gravity)
{
	M_ApproxPosition = M_Position + (M_Velocity + (M_ConstantForce + gravity) * time * 0.8f)*time * 0.8f;

	m_shape->setPosition(sf::Vector2f(
		M_ApproxPosition.x*METERS_TO_PIXELS,
		-M_ApproxPosition.y*METERS_TO_PIXELS));
}

void PhysicsObject::setShapePos()
{
	m_shape->setPosition(sf::Vector2f(
		M_Position.x*METERS_TO_PIXELS,
		GROUND_Y_IN_PIXELS-M_Position.y*METERS_TO_PIXELS));
}

void PhysicsObject::Draw(sf::RenderWindow &window)
{
	if (m_shape != nullptr)
		window.draw(*m_shape);
}

void PhysicsObject::setConstantForce(sf::Vector2f force)
{
	M_ConstantForce = force;
}

void PhysicsObject::UpdateSize()
{
	M_Radius = m_shape->getRadius() / METERS_TO_PIXELS;
	M_Radius_Pow2 = M_Radius*M_Radius;
	M_Mass = 4.f*3.14159f*M_Radius_Pow2*M_Radius/3.f;
}

