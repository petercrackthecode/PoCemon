// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfVLayout.h"



VLayout::VLayout(Widget* parent, bool alignCenter /*= true*/, int maxItems /*= 0*/)
	: Layout(parent), mAlignCenter{ alignCenter }, mMaxItems{ maxItems }
{
}

VLayout::~VLayout()
{
	for (Widget* widget : mChildren)
	{
		if (widget->mParent == this)
			delete widget;
	}
}

Widget* VLayout::at(unsigned int index)const
{
	return mChildren.at(index);
}

sf::Vector2f VLayout::getSize()const
{
	float max_x = 0;
	float y = 0;
	for (Widget* widget : mChildren)
	{
		sf::Vector2f size = widget->getSize();
		if (size.x > max_x)
			max_x = size.x;
		y += mSpace + size.y;
	}
	return sf::Vector2f(max_x + mSpace * 2, y + mSpace);
}

bool VLayout::processEvent(const sf::Event& event, const sf::Vector2f& parentPos)
{
	for (Widget* widget : mChildren)
	{
		if (widget->processEvent(event, parentPos))
			return true;
	}

	return false;
}

void VLayout::processEvents(const sf::Vector2f& parentPos)
{
	for (Widget* widget : mChildren)
		widget->processEvents(parentPos);
}

void VLayout::updateShape()
{
	float max_x = (mParent ? mParent->getSize().x : 0);
	for (Widget* widget : mChildren)
	{
		sf::Vector2f size = widget->getSize();
		float widget_x = size.x;

		if (widget_x > max_x)
			max_x = widget_x;
	}

	float posY = mSpace;
	if (mParent)
		posY = (mParent->getSize().y - getSize().y) / 2.f;

	float offset_x = 0.f;
	int itemCount = 1;

	for (Widget* widget : mChildren)
	{
		sf::Vector2f size = widget->getSize();
		if (mAlignCenter)
			widget->setPosition((max_x + offset_x - size.x) / 2.0, posY);
		else
		{
			widget->setPosition(offset_x, posY);
		}

		if (mMaxItems != 0 && itemCount % mMaxItems == 0)
		{
			offset_x += max_x + (mSpace * (itemCount / mMaxItems));
			posY = 0;
		}
		else
		{
			posY += size.y + mSpace;
		}
		++itemCount;
	}

	Widget::updateShape();

}

void VLayout::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	for (Widget *widget : mChildren)
		target.draw(*widget, states);
}
