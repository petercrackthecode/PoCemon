#ifndef ACTION_H
#define ACTION_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ActionTarget;
class ActionMap;

class Action
{
public:
	enum Type
	{
		RealTime = 1,
		Pressed = 1<<1,
		Released = 1<<2
	};
	Action(const Action& other);
	Action& Action::operator=(const Action& other);
	Action(const sf::Keyboard::Key& key, int type = Type::RealTime | Type::Pressed);
	Action(const sf::Mouse::Button& button, int type = Type::RealTime | Type::Pressed);
	
	bool test() const;
	bool operator==(const sf::Event& event) const;
	bool operator==(const Action& other) const;

private:
	friend class ActionTarget;
	sf::Event mEvent;
	int mType;



};



#endif
