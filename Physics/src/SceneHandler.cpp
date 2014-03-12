#include <SceneHandler.h>
#include <testScene.h>

Scene* SceneHandler::curScene = 0;
int SceneHandler::lastScene = -1;


void SceneHandler::update(float dt)
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1)/* && lastScene != 1*/) || lastScene == -1)
	{
		if (lastScene != -1)
			delete curScene;

		curScene = new testScene();
		lastScene = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F2)/* && lastScene != 2*/)
	{
		delete curScene;
		curScene = new testScene();
		lastScene = 2;
	}
	curScene->Update(dt);
}

void SceneHandler::draw(sf::RenderWindow &window)
{
	curScene->Draw(window);
}

