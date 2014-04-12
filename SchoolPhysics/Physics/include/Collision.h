#pragma once

#include <PhysicsObject.h>

class Collision
{
public:
	Collision(PhysicsObject* GOA, PhysicsObject* GOB, const float CombRad)
		: A(GOA),
		B(GOB),
		combRad(CombRad)
	{
		Bv = B->M_Velocity;
		A_B = B->M_Position - A->M_Position;
		Av = A->M_Velocity;
	}
	~Collision()
	{
	}
	
	PhysicsObject *A;
	PhysicsObject *B;
	// velocity
	sf::Vector2f Av;
	sf::Vector2f Bv;
	// difVector
	sf::Vector2f A_B;
	// combined radius
	float combRad;

};

