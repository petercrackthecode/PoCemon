// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef LABEL_H
#define LABEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "sfWidget.h"

class Label : public Widget
{
public:
	Label(const std::string& text, Widget* parent = nullptr, const sf::Color &color = sf::Color(0, 0, 0));
	Label(Game *game, const std::string& text, Widget* parent = nullptr, const sf::Color &color = sf::Color(0, 0, 0));
	virtual ~Label();
	void setText(const std::string& text);
	void setCharacterSize(int size);
	int getCharacterSize()const;
	void setTextColor(const sf::Color& color);
	void setScale(float factorX, float factorY);
	void setPosition(float factorX, float factorY);
	void setOrigin(float factorX, float factorY);
	virtual sf::Vector2f getSize()const override;
	
private:
	sf::Text mText;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};



#endif