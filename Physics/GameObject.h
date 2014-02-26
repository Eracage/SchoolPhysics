#pragma once

#include <SFML\Graphics.hpp>

class GameObject
{
public:
	enum SHAPE
	{
		NO_SHAPE,
		CIRCLE
	};
	GameObject();
	virtual ~GameObject();
	
	virtual void PreUpdate(float dt){}
	void Update(float dt);
	virtual void PostUpdate(float dt){}
	void setConstantForce(sf::Vector2f force);
	void UpdateSize();
	
	sf::Vector2f M_ConstantForce;
	sf::Vector2f M_Velocity;
	sf::Vector2f M_Position;
	float M_Radius_Pow2;
	SHAPE M_Shape;
protected:
	sf::Shape* m_shape;
};

