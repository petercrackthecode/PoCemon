#ifndef ACTIONTARGET_H
#define ACTIONTARGET_H

#include <functional>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfAction.h"
#include "sfActionMap.h"

//template<typename T>
class ActionTarget
{
public:
	ActionTarget(const ActionTarget&) = delete;
	ActionTarget& operator=(const ActionTarget&) = delete;

	using FuncType = std::function<void(const sf::Event&)>;

	ActionTarget(const ActionMap& map);

	bool processEvent(const sf::Event& event)const;
	void processEvents()const;
	void bind(const Action& action, const FuncType& callback);
	void unbind(const Action& action);

private:
	std::list<std::pair<Action, FuncType>> mEventsRealTime;
	std::list<std::pair<Action, FuncType>> mEventsPoll;

	const ActionMap &mActionMap;
};




#endif
