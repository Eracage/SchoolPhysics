#include <SceneThrowBall.h>
#include <iostream>


SceneThrowBall::SceneThrowBall()
	: m_mouseSPos(0,0),
	m_mouseLPressed(false),
	m_window(nullptr),
	m_throwBall(nullptr)
{
	m_world.setGravity(sf::Vector2f(0.f, -20.f));
	m_world.setTimeStep(0.01f);

}


SceneThrowBall::~SceneThrowBall()
{
}


void SceneThrowBall::Update(float dt)
{

	if (m_window != nullptr)
	{
		if (MB1Pressed())
		{
			m_mouseSPos = m_world.getMousePositionInWorld(*m_window);
			m_throwBall = new Ball(1,sf::Color(rand()%256,rand()%256,rand()%256,255));
			m_throwBall->M_Position = m_mouseSPos;
			m_throwBall->setShapePos();
		}
		else if (MB1Released())
		{
			m_throwBall->M_Velocity = m_mouseSPos - m_world.getMousePositionInWorld(*m_window);
				
			m_world.addToWorld(*m_throwBall);
			delete m_throwBall;
			m_throwBall = nullptr;
		}
	}
	m_mouseLPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	m_world.Update(dt);
}
void SceneThrowBall::Draw(sf::RenderWindow &window)
{
	m_window = &window;
	m_world.Draw(window);
	if (m_throwBall != nullptr)
		m_throwBall->Draw(window);
}

bool SceneThrowBall::MB1Pressed()
{
	return m_mouseLPressed != sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& !m_mouseLPressed;
}
bool SceneThrowBall::MB1Released()
{
	return m_mouseLPressed != sf::Mouse::isButtonPressed(sf::Mouse::Left)
		&& m_mouseLPressed;
}

