#include "GameObject.h"


GameObject::GameObject()
	: M_Velocity(0,0),
	  M_ConstantForce(0,0),
	  M_Position(0,0),
	  M_Shape(NO_SHAPE)
{}


GameObject::~GameObject()
{}

void PreUpdate(float dt)
{

}

void GameObject::Update(float dt)
{
	PreUpdate(dt);

	M_Velocity += M_ConstantForce*dt;

	M_Position += M_Velocity*dt*100.f;
	m_shape->setPosition(M_Position);

	PostUpdate(dt);
}

void PostUpdate(float dt)
{

}

void GameObject::setConstantForce(sf::Vector2f force)
{
	M_ConstantForce = force;
}

void GameObject::UpdateSize()
{
	switch (M_Shape)
	{
	case NO_SHAPE:
		M_Radius_Pow2 = 0;
		break;
	case CIRCLE:
		M_Radius_Pow2 = pow(((sf::CircleShape*)m_shape)->getRadius(),2);
		break;
	}
}