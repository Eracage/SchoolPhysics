#include <SceneLotsOfBalls.h>
#include <iostream>


SceneLotsOfBalls::SceneLotsOfBalls()
	: ballCount(80),
	m_iterations(12),
	m_timestep(0.005f),
	m_time(0),
	m_worldTimer(0),
	m_worldIdles(0),
	m_worldMisses(0),
	idles(0),
	misses(0)
{
	m_world.setGravity(sf::Vector2f(0.f, -10.f));
	m_world.setTimeStep(m_timestep);
	m_world.setIterationCount(m_iterations);
	
	for (int i = 0; i < ballCount; i++)
	{
		AddBall();
	}

	
}

SceneLotsOfBalls::~SceneLotsOfBalls()
{
}

void SceneLotsOfBalls::TextUpdate()
{
	int totalworld = misses + idles + static_cast<int>(2.f/m_timestep);
	float workPercent = (totalworld-idles)*100.f/float(totalworld);
	float missPercent = (misses)*100.f/float(totalworld);

	std::string text("Lots of balls");
	text.append("\n");
	text.append("\nBalls: ").append(std::to_string((_Longlong) m_world.ballCount()));
	text.append("\nFPS: ").append(std::to_string((long double)fps));
	text.append("\n(Works better with multiple iterations in release)");
	text.append("\n");
	text.append("\nIterations: ").append(std::to_string((_Longlong) m_iterations));
	text.append("\nTimestep: ").append(std::to_string((long double) m_timestep));
	text.append("\nWorld Miss % : ").append(std::to_string(long double(missPercent)));
	text.append("\nWorld Work % : ").append(std::to_string(long double(workPercent)));
	text.append("\nUse Left&Right Arrow Keys to adjust Timestep");
	text.append("\nUse Up&Down Arrow Keys to adjust Iterations");
	text.append("\nUse Enter to add balls");
	text.append("\nUse Space to rapidly add balls");


	setOwnText(text);
}


void SceneLotsOfBalls::Update(float dt)
{
	m_worldTimer += dt;
	if (m_worldTimer > 2.f)
	{
		idles = m_worldIdles;
		misses = m_worldMisses;
		m_worldTimer = 0;
		m_worldIdles = 0;
		m_worldMisses = 0;
	}

	m_time += dt;
	if (m_time > 0.2)
	{
		m_time = 0;
		ManageWorld();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		AddBall();
	}

	int worldInfo = m_world.Update(dt);

	switch(worldInfo)
	{
	case 0:
		m_worldIdles++;
		break;
	case 1:
		break;
	default:
		m_worldMisses += worldInfo-1;
		break;
	}


}
void SceneLotsOfBalls::Draw(sf::RenderWindow &window)
{
	m_world.Draw(window);
}

void SceneLotsOfBalls::ManageWorld()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		AddBall();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_timestep*=1.2f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_timestep/=1.2f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_iterations++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (m_iterations > 0)
			m_iterations--;
	}

	m_world.setIterationCount(m_iterations);
	m_world.setTimeStep(m_timestep);
}

void SceneLotsOfBalls::AddBall()
{
		Ball ballToAdd(
			static_cast<float>((rand()%21+20)/50.f),
			sf::Color(rand()%256,rand()%256,rand()%256,255));
		ballToAdd.M_Velocity = sf::Vector2f(
			static_cast<float>(rand()%41-20),
			static_cast<float>(rand()%41-20)
			)/20.f;
		ballToAdd.M_Position = sf::Vector2f(
			static_cast<float>(rand()%41-20),
			static_cast<float>(rand()%30+1)
			);
		ballToAdd.setShapePos();
		m_world.addToWorld(ballToAdd);
}