#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Scene
{
public:

	Scene();
	virtual ~Scene();
	// function to call own update, as well as virtual
	void UpdateScene(float dt);
	virtual void Update(float dt) = 0;
	// function to call own draw, as well as virtual
	void DrawScene(sf::RenderWindow &window);
	virtual void Draw(sf::RenderWindow &window) = 0;

	
	static void setPublicText(const std::string& PublicText);
	const static std::string getPublicText();

	// function called every second to update text objects
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

