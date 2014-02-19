#include "testScene.h"


testScene::testScene()
{
	balls.push_back(Ball(100.f));
	balls[0].setConstantForce(sf::Vector2f(0.f,9.81f));
}


testScene::~testScene()
{
}


void testScene::Update(float dt)
{
	dt/=100;
	for (int i = 0; i < balls.size(); i++)
		balls[i].Update(dt);
}
void testScene::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < balls.size(); i++)
		window.draw(balls[i].shape);
}
