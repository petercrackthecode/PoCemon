#ifndef MENUCONTAINER_H
#define MENUCONTAINER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AssetManager.h"
#include "Game.h"
#include "sfWidget.h"

class MenuContainer : public Widget
{
public:
    MenuContainer(Game* game, const int &numOfDivisions);

	virtual sf::Vector2f getSize() const override { return mFillColor.getSize(); }; // TODO: Make this return the actual size.
	virtual void MenuContainer::draw(sf::RenderTarget& target, sf::RenderStates states) const override;


    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************
private:
    void setLayout(const sf::View &view);

    int divisions;

    sf::Texture *menuTx;

    sf::Sprite mBorderTopLeft;
    sf::Sprite mBorderTopRight;
    sf::Sprite mBorderBottomLeft;
    sf::Sprite mBorderBottomRight;

    sf::Sprite mBorderTop;
    sf::Sprite mBorderRight;
    sf::Sprite mBorderBottom;
    sf::Sprite mBorderLeft;

    sf::Sprite mBorderMidTop;
    sf::Sprite mBorderMidBottom;
    sf::Sprite mBorderMidTop2Bottom;

    sf::Sprite mBorderMidLeft;
    sf::Sprite mBorderMidRight;
    sf::Sprite mBorderMidLeft2Right;

    sf::Sprite mBorderMidMid;

    sf::RectangleShape mFillColor;





};






#endif
