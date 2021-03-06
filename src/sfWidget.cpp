// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#include "sfWidget.h"

using namespace std;

void Widget::attachChild(Widget *child)
{
	child->mParent = this;
	mChildren.push_back(child);
	updateShape();
}


Widget* Widget::detachChild(const Widget &node)
{
	auto found = find_if(mChildren.begin(), mChildren.end(), [&](Widget *p) -> bool { return (p == &node); });
	if (found == mChildren.end())
		throw "Couldn't find child."; // TODO: Class exception.

	Widget* result = *found;
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}


void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

}


void Widget::updateShape()
{
	if (mParent)
		mParent->updateShape();
}

bool Widget::update(const float &dt)
{
	bool wasChanged = false;
	for (auto child : mChildren)
	{
		if (child != nullptr)
			wasChanged = child->update(dt) || wasChanged;
	}
	wasChanged = this->updateSelf(dt) || wasChanged;

	return wasChanged;
};
