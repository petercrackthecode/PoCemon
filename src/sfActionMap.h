#ifndef ACTIONMAP_H
#define ACTIONMAP_H

#include <functional>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfAction.h"


//template <typename T>
class ActionMap
{
public:
	ActionMap(const ActionMap&) = delete;
	ActionMap& operator=(const ActionMap&) = delete;

	ActionMap() = default;
	void map(const int &key, const Action &action);
	const Action& get(const int &key) const;

private:
	std::map<int, Action> mMap;
};


#endif
