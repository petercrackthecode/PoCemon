#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfActionTarget.h"

//template<typename T>
ActionTarget::ActionTarget(const ActionMap &map)
	: mActionMap{ map }
{ }


//template<typename T>
bool ActionTarget::processEvent(const sf::Event& event)const
{
	bool res = false;
	for (auto& action : mEventsPoll)
	{
		if (action.first == event)
		{
			action.second(event);
			res = true;
			break;
		}
	}    return res;
}


//template<typename T>
void ActionTarget::processEvents()const
{
	for (auto& action : mEventsRealTime)
	{
		if (action.first.test())
			action.second(action.first.mEvent);
	}
}


//template<typename T>
void ActionTarget::bind(const Action& action, const FuncType& callback)
{
	if (action.mType & Action::Type::RealTime)
		mEventsRealTime.emplace_back(action, callback);
	else
		mEventsPoll.emplace_back(action, callback);
}


//template<typename T>
void ActionTarget::unbind(const Action& action)
{
	auto remove_func = [&action](const std::pair<Action, FuncType> &pair) -> bool { return pair.first == action; };

	if (action.mType & Action::Type::RealTime)
		mEventsRealTime.remove_if(remove_func);
	else
		mEventsPoll.remove_if(remove_func);
}

