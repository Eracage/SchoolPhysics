#include <SceneBallCollisions.h>
#include <iostream>


SceneBallCollisions::SceneBallCollisions()
	: ballCount(16)
{
	m_world.setGravity(sf::Vector2f(0.f, 0.f));
	m_world.setTimeStep(0.01f);

	std::vector<Ball> balls;
	
	for (int i = 0; i < ballCount; i++)
	{
		balls.push_back(Ball((rand()%81+20)/50.f,sf::Color(rand()%256,rand()%256,rand()%256,255)));
		balls.back().setRadius((rand()%21+40)/50.f);
		balls.back().M_Velocity = sf::Vector2f(rand()%201-100,rand()%201-100)/5.f;
		balls.back().M_Position = sf::Vector2f(rand()%11-5,rand()%10+1);
		balls.back().setShapePos();
	}

	for (size_t i = 0; i < balls.size(); i++)
		m_world.addToWorld(balls[i]);
}


SceneBallCollisions::~SceneBallCollisions()
{
}

void SceneBallCollisions::TextUpdate()
{
	
	std::string text("Ball collision scene (no gravity)");
	text.append("\n");
	text.append("\nBalls: ").append(std::to_string((_Longlong) m_world.ballCount()));
	text.append("\nFPS: ").append(std::to_string((long double)fps));
	text.append("\n");
	text.append("\n");

	setOwnText(text);
}

void SceneBallCollisions::Update(float dt)
{
	m_world.Update(dt);
}
void SceneBallCollisions::Draw(sf::RenderWindow &window)
{
	m_world.Draw(window);
}
