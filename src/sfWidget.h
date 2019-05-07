#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Widget : public sf::Transformable, public sf::Drawable
{
public:
    Widget() : mParent{ nullptr } {};
	virtual ~Widget() {};

	virtual sf::Vector2f getSize() const { return sf::Vector2f(0, 0); };

    void attachChild(Widget* child);
    Widget* detachChild(const Widget& node);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    Widget* mParent;
    std::vector<Widget*> mChildren;

	virtual bool processEvent(const sf::Event &event, const sf::Vector2f &parentPos) { return false; };
	virtual void processEvents(const sf::Vector2f &parentPos) {};
	virtual void updateShape();
};


#endif
