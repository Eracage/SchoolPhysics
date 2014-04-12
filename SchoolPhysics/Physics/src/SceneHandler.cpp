#include <SceneHandler.h>

#include <BallScene.h>
#include <SceneBallCollisions.h>
#include <SceneLotsOfBalls.h>
#include <SceneThrowBall.h>

Scene* SceneHandler::curScene = 0;
int SceneHandler::lastScene = -1;



void SceneHandler::update(float dt)
{

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) || lastScene == -1)
	{
		if (lastScene != -1)
			delete curScene;

		curScene = new BallScene();
		lastScene = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
	{
		delete curScene;
		curScene = new SceneBallCollisions();
		lastScene = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
	{
		if (lastScene != -1)
			delete curScene;

		curScene = new SceneLotsOfBalls();
		lastScene = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
	{
		delete curScene;
		curScene = new SceneThrowBall();
		lastScene = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		dt /= 20;
	curScene->UpdateScene(dt);
}

void SceneHandler::draw(sf::RenderWindow &window)
{
	curScene->DrawScene(window);
}

