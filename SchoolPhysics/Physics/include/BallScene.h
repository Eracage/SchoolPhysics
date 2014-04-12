#pragma once

#include <scene.h>
#include <World.h>
#include <Ball.h>

class BallScene :
	public Scene
{
public:
	BallScene();
	~BallScene();
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow &window);
	void TextUpdate();
private:
	World m_world;

	const int ballCount;
};