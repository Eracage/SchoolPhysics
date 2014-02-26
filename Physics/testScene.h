#pragma once

#include "scene.h"
#include "Ball.h"

class testScene :
	public Scene
{
public:
	testScene();
	~testScene();
	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow &window);
private:
	std::vector<Ball> balls;
};

