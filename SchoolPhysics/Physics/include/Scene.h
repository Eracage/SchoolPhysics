#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Scene
{
public:

	Scene();
	virtual ~Scene();
	void UpdateScene(float dt);
	virtual void Update(float dt) = 0;
	void DrawScene(sf::RenderWindow &window);
	virtual void Draw(sf::RenderWindow &window) = 0;

	static void setPublicText(const std::string& PublicText);
	const static std::string getPublicText();

	virtual void TextUpdate() = 0;
protected:
	int fps;
	void setOwnText(const std::string& PrivateText);
	const std::string getOwnText();

private:
	int scene;

	int m_fps;
	float m_second;

	
	sf::Text m_textPrivate;
	std::string m_privateText;

	sf::Font m_font;
	sf::Text m_textPublic;
	static std::string m_publicText;
};

