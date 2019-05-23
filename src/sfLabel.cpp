// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AssetManager.h"
#include "sfLabel.h"


Label::Label(const std::string& text, Widget* parent /*= nullptr*/, const sf::Color &color /*= sf::Color(0, 0, 0)*/)
	: Widget{ parent }
{
	sf::Font a;
	a.loadFromFile("graphics/gbFont.ttf");
	mText.setFont(a);
	setText(text);
	setTextColor(color);
}

Label::Label(Game *game, const std::string& text, Widget* parent /*= nullptr*/, const sf::Color &color /*= sf::Color(0, 0, 0)*/)
	: Widget{ parent }
{
	mText.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	setText(text);
	setTextColor(color);
}


Label::~Label()
{}


void Label::setText(const std::string& text)
{
	mText.setString(text);
	updateShape();
}


void Label::setCharacterSize(int size)
{
	mText.setCharacterSize(size);
	updateShape();
}


int Label::getCharacterSize() const
{
	return mText.getCharacterSize();
}


void Label::setTextColor(const sf::Color &color)
{
	mText.setColor(color);
}


void Label::setScale(float factorX, float factorY)
{
	Transformable::setScale(factorX, factorY);
	mText.setScale(getScale().x, getScale().y);
	updateShape();
}


void Label::setPosition(float factorX, float factorY)
{
	Transformable::setPosition(factorX, factorY);
	//mText.setPosition(getPosition().x, getPosition().x);
	updateShape();
}

void Label::setOrigin(float factorX, float factorY)
{
	Transformable::setOrigin(factorX, factorY);
	mText.setOrigin(factorX, factorY);
	
	//updateShape();
}


sf::Vector2f Label::getSize() const
{
	sf::FloatRect rect = mText.getGlobalBounds();
	return sf::Vector2f(rect.width, rect.height);
}


void Label::draw(sf::RenderTarget& target, sf::RenderStates    states) const
{
	states.transform.translate(getPosition());
	target.draw(mText, states);
}