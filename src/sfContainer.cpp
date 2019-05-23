#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sfContainer.h"
#include "sfLayout.h"

Container::Container(Widget* parent)
	: Widget{ parent }, mLayout{ nullptr }
{}


Container::~Container()
{
	if (mLayout != nullptr && mLayout->mParent == this)
	{
		mLayout->mParent = nullptr;
		delete mLayout;
	}
}


void Container::setLayout(Layout *layout)
{
	if (mLayout != nullptr && mLayout->mParent == this)
	{
		mLayout->mParent = nullptr;
		detachChild(mLayout);
	}

	if ((mLayout = layout) != nullptr)
	{

		mLayout->mParent = this;
		mLayout->updateShape();
		attachChild(mLayout);
	}
}


Layout* Container::getLayout() const
{
	return mLayout;
}


sf::Vector2f Container::getSize() const
{
	sf::Vector2f res(0, 0);

	if (mLayout)
		res = mLayout->getSize();

	return res;
}


void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//states.transform.translate(getPosition());
	if (mLayout)
		target.draw(*mLayout, states);
}



bool Container::processEvent(const sf::Event& event, const sf::Vector2f& parentPos)
{
	bool res = false;
	if (mLayout)
		res = mLayout->processEvent(event, parentPos);
	return res;
}


void Container::processEvents(const sf::Vector2f& parentPos)
{
	if (mLayout)
		mLayout->processEvents(parentPos);
}
