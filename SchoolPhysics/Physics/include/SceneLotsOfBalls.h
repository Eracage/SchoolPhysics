#pragma once

#include <scene.h>
#include <World.h>
#include <Ball.h>

class SceneLotsOfBalls :
	public Scene
{
public:
	SceneLotsOfBalls();
	~SceneLotsOfBalls();
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow &window);
	void TextUpdate();
	void ManageWorld();
private:
	World m_world;

	const int ballCount;

	unsigned int m_iterations;

	float m_worldTimer;
	int m_worldIdles;
	int m_worldMisses;
	int idles;
	int misses;

	float m_timestep;
	float m_time;
};