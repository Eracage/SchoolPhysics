#pragma once

#include <scene.h>
#include <World.h>
#include <Ball.h>

class SceneBallCollisions :
	public Scene
{
public:
	SceneBallCollisions();
	~SceneBallCollisions();
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow &window);
private:
	World m_world;

	const int ballCount;
};