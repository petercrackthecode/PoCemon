// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef FRAME_H
#define FRAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "sfActionTarget.h"
#include "sfContainer.h"


class Frame : public Container, protected ActionTarget
{
public:
	using ActionTarget::FuncType;
	Frame(Game &game);
	virtual ~Frame();
	void processEvents();

	bool processEvent(const sf::Event &event);
	void bind(const Action &action, const FuncType &callback);
	void unbind(const Action &action);
	void draw();
	virtual sf::Vector2f getSize() const override;

private:
	sf::RenderWindow& mWindow;
	virtual bool processEvent(const sf::Event &event, const sf::Vector2f &parentPos) override;
	virtual void processEvents(const sf::Vector2f &parentPos) override;

};


#endif
