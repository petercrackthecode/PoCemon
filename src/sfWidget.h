// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Widget : public sf::Transformable, public sf::Drawable
{
public:
    Widget() : mParent{ nullptr } {};
	Widget(Widget *parent) : mParent{ parent } {}
	virtual ~Widget() {};

	virtual sf::Vector2f getSize() const { return sf::Vector2f(0, 0); };

    virtual void attachChild(Widget* child);
    virtual Widget* detachChild(const Widget& node);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual bool processEvent(const sf::Event &event, const sf::Vector2f &parentPos) { return false; };
	virtual void processEvents(const sf::Vector2f &parentPos) {};

	virtual bool update(const float &dt);

    Widget* mParent;
    std::vector<Widget*> mChildren;

protected:
	virtual void updateShape();
	virtual bool updateSelf(const float &dt) { return false; };
};


#endif
