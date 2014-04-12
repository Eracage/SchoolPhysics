#include <SceneLotsOfBalls.h>
#include <iostream>


SceneLotsOfBalls::SceneLotsOfBalls()
	: ballCount(120)

{
	m_world.setGravity(sf::Vector2f(0.f, -20.f));
	m_world.setTimeStep(0.005f);
	m_world.setIterationCount(60);

	std::vector<Ball> balls;
	
	for (int i = 0; i < ballCount; i++)
	{
		balls.push_back(Ball((rand()%81+20)/50.f,sf::Color(rand()%256,rand()%256,rand()%256,255)));
		balls.back().M_Velocity = sf::Vector2f(rand()%41-20,rand()%41-20)/20.f;
		balls.back().M_Position = sf::Vector2f(rand()%41-20,rand()%30+1);
		balls.back().setShapePos();
	}

	for (size_t i = 0; i < balls.size(); i++)
		m_world.addToWorld(balls[i]);

	
}

SceneLotsOfBalls::~SceneLotsOfBalls()
{
}

void SceneLotsOfBalls::TextUpdate()
{
	std::string text("Lots of balls");
	text.append("\n");
	text.append("\nBalls: ").append(std::to_string((_Longlong) m_world.ballCount()));
	text.append("\nFPS: ").append(std::to_string((long double)fps));
	text.append("\n");
	text.append("\n");

	setOwnText(text);
}


void SceneLotsOfBalls::Update(float dt)
{

	m_world.Update(dt);
}
void SceneLotsOfBalls::Draw(sf::RenderWindow &window)
{
	m_world.Draw(window);
}
