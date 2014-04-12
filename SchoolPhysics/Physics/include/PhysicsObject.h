#pragma once
#include <SFML\Graphics.hpp>


class PhysicsObject
{
public:
	PhysicsObject();
	virtual ~PhysicsObject();

	void CreateImpulse();
	
	void PreColUpdate(float timestep, const sf::Vector2f& gravity);
	void PostColUpdate(float timestep, const sf::Vector2f& gravity);
	void ApproxUpdate(float time, const sf::Vector2f& gravity);

	void setShapePos();

	virtual void Draw(sf::RenderWindow &window);

	void setConstantForce(sf::Vector2f force);
	void UpdateSize();


	
	sf::Vector2f M_ConstantForce;
	sf::Vector2f M_Velocity;
	sf::Vector2f M_Position;
	sf::Vector2f M_ApproxPosition;
	float M_Radius;
	float M_Mass;
	float M_Bounciness;
	float M_Friction;
	bool M_StaticCollision;
protected:
	sf::CircleShape* m_shape;
};
