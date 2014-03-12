#include <testScene.h>
#include <iostream>


testScene::testScene()
{
	objects.push_back(Ball());
	objects[0].setConstantForce(sf::Vector2f(0.f,-9.81f));
	objects[0].M_Position = sf::Vector2f(5,5);
}


testScene::~testScene()
{
}


void testScene::Update(float dt)
{
	//dt/=1000;
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i].Update(dt);
		std::cout<<objects[i].M_Velocity.x<<","<<objects[i].M_Velocity.y<<std::endl;
	}
}
void testScene::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < objects.size(); i++)
		objects[i].Draw(window);
}
