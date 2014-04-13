#pragma once
#include <SFML\Graphics.hpp>

// Object parent to communicate with Physical World
// not to be used as variable, world copies this
// can be taken as variable with World::accessObject() function
class PhysicsObject
{
public:
	PhysicsObject();
	virtual ~PhysicsObject();

	// update before collision, adds half of constant forces to velocity and moves object
	void PreColUpdate(float timestep, const sf::Vector2f& gravity);
	// adds another half of constant forces, updates position
	void PostColUpdate(float timestep, const sf::Vector2f& gravity);
	// should approximate the next position of the object
	void ApproxUpdate(float time, const sf::Vector2f& gravity);

	// sets the position of drawable circle shape
	void setShapePos();

	virtual void Draw(sf::RenderWindow &window);

	// sets force constantly affecting the object, similiar to gravity
	void setConstantForce(sf::Vector2f force);
	// updates radius and mass variables according to shape
	void UpdateSize();


	
	sf::Vector2f M_ConstantForce;
	sf::Vector2f M_Velocity;
	sf::Vector2f M_ApproxPosition;
	sf::Vector2f M_Position;
	float M_Radius;
	float M_Mass;
	float M_Bounciness;
	float M_Friction;
	unsigned int M_StaticCollision;
protected:
	sf::CircleShape* m_shape;
};
