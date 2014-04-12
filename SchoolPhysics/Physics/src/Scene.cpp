#include <Scene.h>

std::string Scene::m_publicText;

Scene::Scene(void)
	: m_fps(0),
	m_second(0.f),
	fps(0)
{
	m_font.loadFromFile("font.ttf");

	m_textPublic.setFont(m_font);
	m_textPublic.setColor(sf::Color::White);
	m_textPublic.setScale(0.8f,0.8f);

	m_textPrivate.setFont(m_font);
	m_textPrivate.setColor(sf::Color::White);
	m_textPrivate.setScale(0.6f,0.6f);
	m_textPrivate.setPosition(0,240);
}


Scene::~Scene(void)
{
}
void Scene::UpdateScene(float dt)
{
	m_second += dt;
	m_fps++;
	if (m_second > 1)
	{
		fps = m_fps;
		m_fps = 0;
		m_second = 0;
	}

	Update(dt);
}


void Scene::DrawScene(sf::RenderWindow &window)
{
	Draw(window);

	TextUpdate();
	m_textPrivate.setString(m_privateText);
	m_textPublic.setString(m_publicText);

	window.draw(m_textPrivate);
	window.draw(m_textPublic);
}

void Scene::setPublicText(const std::string& PublicText)
{
	m_publicText = PublicText;
}
const std::string Scene::getPublicText()
{
	return m_publicText;
}


void Scene::setOwnText(const std::string& PrivateText)
{
	m_privateText = PrivateText;
}
const std::string Scene::getOwnText()
{
	return m_privateText;
}
