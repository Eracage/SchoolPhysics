#pragma once

#include <scene.h>
#include <World.h>
#include <Ball.h>

class SceneThrowBall :
	public Scene
{
public:
	SceneThrowBall();
	~SceneThrowBall();
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow &window);

	bool MB1Pressed();
	bool MB1Released();
private:
	World m_world;

	bool m_mouseLPressed;
	sf::Vector2f m_mouseSPos;

	sf::RenderWindow* m_window;

	Ball* m_throwBall;
};