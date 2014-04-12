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
	void MoveBall(float dt, int ID = 0, float strenght = 10.f);
private:
	World m_world;

	int mode;

	const int ballCount;
};