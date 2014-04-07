#pragma once
#ifndef PHYSICSOBJECT_H_EGE2D
#define PHYSICSOBJECT_H_EGE2D

#include <World.h>
#include <PhysicsObject.h>


namespace EGE2D
{
	const static float METERS_TO_PIXELS = 50;
	const static float GROUND_Y_IN_PIXELS = 700;
	namespace PhysicsShape
	{
		enum SHAPE
		{
			NO_SHAPE,
			CIRCLE
		};
	}

	class PhysicsObject
	{
	public:
		PhysicsObject();
		virtual ~PhysicsObject();

		void CreateImpulse();
		void MoveTo();
		void Teleport();
	
		virtual void PreUpdate(float dt);
		void Update(float dt);
		virtual void PostUpdate(float dt);

		virtual void Draw(sf::RenderWindow &window);

		void setConstantForce(sf::Vector2f force);
		void UpdateSize();


	
		sf::Vector2f M_ConstantForce;
		sf::Vector2f M_Velocity;
		sf::Vector2f M_Position;
		float M_Radius_Pow2;
		PhysicsShape::SHAPE M_Shape;
	protected:
		sf::Shape* m_shape;
	};
}

#endif