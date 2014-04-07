#pragma once

#include <GameObject.h>

class Collision
{
public:
	Collision(GameObject *GOA, GameObject *GOB)
	{
		A = GOA;
		B = GOB;
	}
	~Collision()
	{
		A = NULL;
		B = NULL;
	}
	void Copy()
	{
		Av = A->M_Velocity;
		Bv = B->M_Velocity;
		Ap = A->M_Position;
		Bp = B->M_Position;
	}
	
	GameObject *A;
	GameObject *B;
	// velocity
	sf::Vector2f Av;
	// velocity
	sf::Vector2f Bv;
	// position
	sf::Vector2f Ap;
	// position
	sf::Vector2f Bp;
};

