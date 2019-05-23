#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "sfActionMap.h"

//template <typename T>
void ActionMap::map(const int &key, const Action &action)
{
	mMap.emplace(key, action);
}


//template <typename T>
const Action& ActionMap::get(const int &key) const
{
	return mMap.at(key);
}