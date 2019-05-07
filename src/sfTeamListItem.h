#ifndef TEAMLISTITEM_H
#define TEAMLISTITEM_H

#include "PoCemon.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class TeamListItem
{
public:
    TeamListItem(Pocemon &p, sf::Vector2f &pos, const float &scale, sf::Font &font, sf::Texture &texture);

    void update();

    void Render(sf::RenderWindow &window, int iFrame);

    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************
    Pocemon *poce;
    sf::Text nameText;
    sf::Sprite poceSprite;
    const int SPRITESIZE = 32;
    int iPoce;
    
    



};





#endif
