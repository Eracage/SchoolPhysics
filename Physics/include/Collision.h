#pragma once

#include <PhysicsObject.h>

class Collision
{
public:
	Collision(PhysicsObject* GOA, PhysicsObject* GOB)
		: A(GOA),
		B(GOB)
	{
		//Av = A.M_Velocity;
		//Bv = B.M_Velocity;
		//Ap = A.M_Position;
		//Bp = B.M_Position;
	}
	~Collision()
	{
	}
	void Copy()
	{
		//Av = A.M_Velocity;
		//Bv = B.M_Velocity;
		//Ap = A.M_Position;
		//Bp = B.M_Position;
	}
	
	PhysicsObject *A;
	PhysicsObject *B;
	// velocity
	sf::Vector2f Av;
	// velocity
	sf::Vector2f Bv;
	// position
	sf::Vector2f Ap;
	// position
	sf::Vector2f Bp;
};

