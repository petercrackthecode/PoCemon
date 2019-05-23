// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfLayout.h"

Layout::Layout(Widget* parent)
	: Widget{ parent }, mSpace{ 5 }
{
	//setPosition(parent->getPosition());
}


Layout::~Layout()
{
}


void Layout::setSpace(float pixels)
{
	if (pixels >= 0)
	{
		mSpace = pixels;
		updateShape();
	}
	else
		throw std::invalid_argument("pixel value must be >= 0");
}


