// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef VLAYOUT_H
#define VLAYOUT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfLayout.h"

class VLayout : public Layout
{
public:
	VLayout(const VLayout&) = delete;
	VLayout& operator=(const VLayout&) = delete;

	VLayout(Widget* parent = nullptr, bool alignCenter = true, int maxItems = 0);
	~VLayout();

	Widget* at(unsigned int index) const;

	virtual sf::Vector2f getSize() const override;

protected:
	virtual bool processEvent(const sf::Event &event, const sf::Vector2f &parentPos) override;
	virtual void processEvents(const sf::Vector2f &parentPos) override;
	bool mAlignCenter;
	int mMaxItems;

private:

	virtual void updateShape() override;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif
