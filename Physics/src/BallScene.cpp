#include <BallScene.h>
#include <iostream>


BallScene::BallScene()
	: ballCount(1)
{
	m_world.setGravity(sf::Vector2f(0.f, -20.f));
	m_world.setTimeStep(0.01f);

	std::vector<Ball> balls;
	
	for (int i = 0; i < ballCount; i++)
	{
		balls.push_back(Ball());
		//balls.back().setConstantForce(sf::Vector2f(0.f,-9.81f));
		balls.back().M_Velocity = sf::Vector2f(5,5);
		balls.back().M_Position = sf::Vector2f(5,5);
		balls.back().setShapePos();
	}

	for (size_t i = 0; i < balls.size(); i++)
		m_world.addToWorld(balls[i]);
}


BallScene::~BallScene()
{
}


void BallScene::Update(float dt)
{
	m_world.Update(dt);
}
void BallScene::Draw(sf::RenderWindow &window)
{
	m_world.Draw(window);
}
