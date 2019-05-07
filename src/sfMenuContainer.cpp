
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AssetManager.h"
#include "sfMenuContainer.h"

MenuContainer::MenuContainer(Game* game, const int &numOfDivisions)
    : divisions{ numOfDivisions }
{
    menuTx = &(game->mAssetMgr.getTextureRef(TextureId::BattleMenuBorder));
    setLayout(game->mWindow.getView());
}

void MenuContainer::setLayout(const sf::View &view)
{
    unsigned int x = view.getSize().x;
    unsigned int y = view.getSize().y;
    unsigned int xSize = x - 16;
    unsigned int ySize = y - 16 - (3 * y) / 5;

    mBorderTopLeft = sf::Sprite(*menuTx, sf::IntRect(0, 0, 8, 8));
    mBorderTopRight = sf::Sprite(*menuTx, sf::IntRect(16, 0, 8, 8));
    mBorderBottomRight = sf::Sprite(*menuTx, sf::IntRect(16, 16, 8, 8));
    mBorderBottomLeft = sf::Sprite(*menuTx, sf::IntRect(0, 16, 8, 8));

    mBorderTop = sf::Sprite(*menuTx, sf::IntRect(8, 0, 8, 8));
    mBorderRight = sf::Sprite(*menuTx, sf::IntRect(16, 8, 8, 8));
    mBorderBottom = sf::Sprite(*menuTx, sf::IntRect(8, 16, 8, 8));
    mBorderLeft = sf::Sprite(*menuTx, sf::IntRect(0, 8, 8, 8));

    if (divisions > 0)
    {
        mBorderMidTop = sf::Sprite(*menuTx, sf::IntRect(24, 0, 8, 8));
        mBorderMidBottom = sf::Sprite(*menuTx, sf::IntRect(24, 16, 8, 8));
        mBorderMidTop2Bottom = sf::Sprite(*menuTx, sf::IntRect(24, 8, 8, 8));

        if (divisions > 1)
        {
            mBorderMidLeft = sf::Sprite(*menuTx, sf::IntRect(0, 24, 8, 8));
            mBorderMidRight = sf::Sprite(*menuTx, sf::IntRect(16, 24, 8, 8));
            mBorderMidLeft2Right = sf::Sprite(*menuTx, sf::IntRect(8, 24, 8, 8));

            mBorderMidMid = sf::Sprite(*menuTx, sf::IntRect(24, 24, 8, 8));
        }
    }

    unsigned int xLeft = 0;
    unsigned int xRight = x - 8;
    unsigned int xMid = (x / 2) - 8;

    unsigned int yTop = (3 * y) / 5;
    unsigned int yBottom = y - 8;
    unsigned int yMid = yTop + ((y - yTop) / 2) - 8;

    mFillColor = sf::RectangleShape(sf::Vector2f(xSize + 16, ySize + 16));
    mFillColor.setFillColor(sf::Color(240, 232, 240, 255));
    mFillColor.setOutlineColor(sf::Color(0, 0, 0, 255));
    mFillColor.setOutlineThickness(-2.f);
    mFillColor.setPosition(xLeft, yTop);

    mBorderTopLeft.setPosition(xLeft, yTop);
    mBorderTopRight.setPosition(xRight, yTop);
    mBorderBottomLeft.setPosition(xLeft, yBottom);
    mBorderBottomRight.setPosition(xRight, yBottom);

    mBorderTop.setPosition(xLeft + 8, yTop);
    mBorderRight.setPosition(xRight, yTop + 8);
    mBorderBottom.setPosition(xLeft + 8, yBottom);
    mBorderLeft.setPosition(xLeft, yTop + 8);

    mBorderTop.setScale(xSize / 8.f, 1.f);
    mBorderRight.setScale(1.f, ySize / 8.f);
    mBorderBottom.setScale(xSize / 8.f, 1.f);
    mBorderLeft.setScale(1.f, ySize / 8.f);

    if (divisions > 0)
    {
        mBorderMidTop.setPosition(xMid, yTop);
        mBorderMidBottom.setPosition(xMid, yBottom);
        mBorderMidTop2Bottom.setPosition(xMid, yTop + 8);

        mBorderMidTop2Bottom.setScale(1.f, ySize / 8.f);

        if (divisions > 1)
        {
            mBorderMidLeft.setPosition(xLeft, yMid);
            mBorderMidRight.setPosition(xRight, yMid);
            mBorderMidLeft2Right.setPosition(xLeft + 8, yMid);

            mBorderMidMid.setPosition(xMid, yMid);

            mBorderMidLeft2Right.setScale(xSize / 8.f, 1.f);
        }
    }

}


void MenuContainer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mFillColor, states);

	// draw children here.

    target.draw(mBorderTopLeft, states);
    target.draw(mBorderTopRight, states);
    target.draw(mBorderBottomLeft, states);
    target.draw(mBorderBottomRight, states);

    target.draw(mBorderTop, states);
    target.draw(mBorderRight, states);
    target.draw(mBorderBottom, states);
    target.draw(mBorderLeft, states);
    if (divisions > 0)
    {
        target.draw(mBorderMidTop, states);
        target.draw(mBorderMidBottom, states);
        target.draw(mBorderMidTop2Bottom, states);

        if (divisions > 1)
        {
            target.draw(mBorderMidLeft, states);
            target.draw(mBorderMidRight, states);
            target.draw(mBorderMidLeft2Right, states);

            target.draw(mBorderMidMid, states);
        }
    }
}


