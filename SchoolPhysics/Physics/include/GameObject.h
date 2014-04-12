#pragma once

#include <SFML\Graphics.hpp>
#include <PhysicsObject.h>
#include <World.h>


// not too useful class now, since I made drawing in physic object, that thing could change
class GameObject : public PhysicsObject
{
public:
	GameObject();
	virtual ~GameObject();
protected:
};

