#include <BallScene.h>
#include <iostream>


BallScene::BallScene()
	: ballCount(50),
	mode(2)
{
	m_world.setGravity(sf::Vector2f(0.f, -20.f));
	m_world.setTimeStep(0.01f);

	std::vector<Ball> balls;
	
	for (int i = 0; i < ballCount; i++)
	{
		balls.push_back(Ball((rand()%81+20)/50.f,sf::Color(rand()%256,rand()%256,rand()%256,255)));
		balls.back().setRadius((rand()%41+10)/50.f);
		balls.back().M_Velocity = sf::Vector2f(rand()%21-10,rand()%21-10)/50.f;
		balls.back().M_Position = sf::Vector2f(rand()%11-5,rand()%10+1);
		balls.back().setShapePos();
	}
	balls[0].setConstantForce(sf::Vector2f(0.f,20.f));

	for (size_t i = 0; i < balls.size(); i++)
		m_world.addToWorld(balls[i]);

}


BallScene::~BallScene()
{
}

void BallScene::TextUpdate()
{

	std::string text("Basic Ball Physics");
	text.append("\n");
	text.append("\nBalls:").append(std::to_string((_Longlong) m_world.ballCount()));
	text.append("\nFPS: ").append(std::to_string((long double)fps));
	text.append("\n");
	text.append("\nMove the ball with WASD or Arrow Keys");
	text.append("\nThe ball has antigravity");
	text.append("\nPress 1 to move object by position");
	text.append("\nPress 2 to move object with force");
	text.append("\nPress 3 to add to constant force");
	text.append("\n affecting the object");
	text.append("\nPress 4 to reset all forces");
	text.append("\n affecting the object");

	setOwnText(text);
}


void BallScene::Update(float dt)
{
	MoveBall(dt,0,25);
	m_world.Update(dt);
}
void BallScene::Draw(sf::RenderWindow &window)
{
	m_world.Draw(window);
}

void BallScene::MoveBall(float dt, int ID, float strenght)
{
	PhysicsObject& obj = m_world.accessObject(ID);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		mode = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		mode = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		mode = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		mode = 4;

	int horizontal =
		(sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) -
		(sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
	int vertical = 
		(sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) -
		(sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
	
	switch (mode)
	{
	case 1:
		obj.M_Position.x += horizontal * dt * strenght;
		obj.M_Position.y += vertical * dt * strenght;
		break;
	case 2:
		obj.M_Velocity.x += horizontal * dt * strenght;
		obj.M_Velocity.y += vertical * dt * strenght;
		break;
	case 3:
		obj.M_ConstantForce.x += horizontal * dt * strenght;
		obj.M_ConstantForce.y += vertical * dt * strenght;
		break;
	case 4:
		obj.M_Position.x += horizontal * dt * strenght;
		obj.M_Position.y += vertical * dt * strenght;
		obj.M_Velocity.x = 0;
		obj.M_Velocity.y = 0;
		obj.M_ConstantForce.x = 0;
		obj.M_ConstantForce.y = 0;
		break;
	}
}
