#include "sfWidget.h"

using namespace std;

void Widget::attachChild(Widget *child)
{
    child->mParent = this;
    mChildren.push_back(child);
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