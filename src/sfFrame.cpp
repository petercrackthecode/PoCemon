#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameState.h"
#include "sfFrame.h"
#include "sfAction.h"


Frame::Frame(Game& game)
	: Container{ nullptr }, ActionTarget{ game.peekState()->mActionMap }, mWindow(game.mWindow)
{}


Frame::~Frame()
{}


void Frame::draw()
{
	mWindow.draw(*this);
}


void Frame::bind(const Action &action, const FuncType  &callback)
{
	ActionTarget::bind(action, callback);
}


void Frame::unbind(const Action &action)
{
	ActionTarget::unbind(action);
}


sf::Vector2f Frame::getSize() const
{
	sf::Vector2u size = mWindow.getSize();
	return sf::Vector2f(size.x, size.y);
}

bool Frame::processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)
{
	bool res = ActionTarget::processEvent(event);
	if (!res)
		res = Container::processEvent(event, parent_pos);
	return res;
}

void Frame::processEvents(const sf::Vector2f& parent_pos)
{
	ActionTarget::processEvents();
	Container::processEvents(parent_pos);

	sf::Event event;
	while (mWindow.pollEvent(event))
		Container::processEvent(event, parent_pos);
}