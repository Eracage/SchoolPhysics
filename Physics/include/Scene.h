#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
public:
	Scene(void);
	~Scene(void);
	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow &window) = 0;

private:
	int scene;
};

