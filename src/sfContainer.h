// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef CONTAINER_H
#define CONTAINER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfLayout.h"
#include "sfWidget.h"


class Container : public Widget {
public:
	Container(Widget *parent = nullptr);
	virtual ~Container();
	void setLayout(Layout *layout);
	Layout* getLayout()const;
	virtual sf::Vector2f getSize()const override;

protected:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	virtual bool processEvent(const sf::Event &event, const sf::Vector2f &parentPos)override;
	virtual void processEvents(const sf::Vector2f &parentPos) override;

private:
	Layout *mLayout;
};



#endif
