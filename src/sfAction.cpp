#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "sfAction.h"

Action::Action(const Action& other)
	: mType{ other.mType }, mEvent{ other.mEvent }
{}


Action& Action::operator=(const Action& other)
{
	mEvent = other.mEvent;
	mType = other.mType;
	return *this;
}


Action::Action(const sf::Keyboard::Key& key, int type)
	: mType(type)
{
	mEvent.type = sf::Event::EventType::KeyPressed;
	mEvent.key.code = key;
}


Action::Action(const sf::Mouse::Button& button, int type)
	: mType(type)
{
	mEvent.type = sf::Event::EventType::MouseButtonPressed;
	mEvent.mouseButton.button = button;
}

bool Action::operator==(const sf::Event& event) const
{
	bool res = false;

	switch (event.type) {
	case sf::Event::EventType::KeyPressed:
		if (mType & Type::Pressed && mEvent.type == sf::Event::EventType::KeyPressed)
			res = event.key.code == mEvent.key.code;
		break;

	case sf::Event::EventType::KeyReleased:
		if (mType & Type::Released && mEvent.type == sf::Event::EventType::KeyPressed)
			res = event.key.code == mEvent.key.code;
		break;

	case sf::Event::EventType::MouseButtonPressed:
		if (mType & Type::Pressed && mEvent.type == sf::Event::EventType::MouseButtonPressed)
			res = event.mouseButton.button == mEvent.mouseButton.button;
		break;

	case sf::Event::EventType::MouseButtonReleased:
		if (mType & Type::Released && mEvent.type == sf::Event::EventType::MouseButtonPressed)
			res = event.mouseButton.button == mEvent.mouseButton.button;
		break;

	default: break;
	}

	return res;
}


bool Action::operator==(const Action& other) const
{
	return mType == other.mType && other == mEvent;
}


bool Action::test() const
{
	bool res = false;
	if (mEvent.type == sf::Event::EventType::KeyPressed)
	{
		if (mType & Type::Pressed)
			res = sf::Keyboard::isKeyPressed(mEvent.key.code);
	}
	else if (mEvent.type == sf::Event::EventType::MouseButtonPressed)
	{
		if (mType & Type::Pressed)
			res = sf::Mouse::isButtonPressed(mEvent.mouseButton.button);
	}
	
	return res;
}
