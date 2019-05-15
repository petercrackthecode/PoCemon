#include "sfTeamListItem.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


sfTeamListItem::sfTeamListItem(Pocemon &p, sf::Vector2f& pos, const float &scale, sf::Font &font, sf::Texture &texture) : poce{ &p }, iPoce{ static_cast<int>(poce->getId()) }
{
    poceSprite.setPosition(pos);
    poceSprite.setTexture(texture);
    poceSprite.setScale(sf::Vector2f(scale/2, scale/2));
    nameText.setFont(font);
    nameText.setCharacterSize(3*scale);
    nameText.setFillColor(sf::Color::White);
    nameText.setPosition(sf::Vector2f(pos.x + SPRITESIZE* scale / 2 + scale, pos.y + scale*2));

    update();
}

void sfTeamListItem::update()
{
    nameText.setString(poce->getName());
}

void sfTeamListItem::Render(sf::RenderWindow &window, int iFrame)
{
    poceSprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoce), ((SPRITESIZE)* iFrame), SPRITESIZE, SPRITESIZE));
    window.draw(nameText);
    window.draw(poceSprite);
}
