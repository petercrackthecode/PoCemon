// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef LAYOUT_H
#define LAYOUT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfWidget.h"

class Layout : public Widget
{
public:
	Layout(const Layout&) = delete;
	Layout& operator=(const Layout&) = delete;

	Layout(Widget *parent = nullptr);
	virtual ~Layout();

	void setSpace(float pixels);

protected:
	friend class Container;

	float mSpace;
};






#endif
