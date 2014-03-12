#include <GameObject.h>

//float METERS_TO_PIXELS = 50;
//float GROUND_Y_IN_PIXELS = 700;

GameObject::GameObject()
	: M_Velocity(0,0),
	  M_ConstantForce(0,0),
	  M_Position(0,0),
	  M_Shape(NO_SHAPE)
{}


GameObject::~GameObject()
{}

void GameObject::PreUpdate(float dt)
{

}

void GameObject::Update(float dt)
{
	PreUpdate(dt);

	M_Velocity += M_ConstantForce*dt;

	M_Position += M_Velocity*dt;
	m_shape->setPosition(sf::Vector2f(
		M_Position.x*METERS_TO_PIXELS,
		-M_Position.y*METERS_TO_PIXELS+GROUND_Y_IN_PIXELS));

	PostUpdate(dt);
}

void GameObject::PostUpdate(float dt)
{

}

void GameObject::Draw(sf::RenderWindow &window)
{
	window.draw(*m_shape);
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
