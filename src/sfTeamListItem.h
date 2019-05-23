#ifndef TEAMLISTITEM_H
#define TEAMLISTITEM_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "PoCemon.h"
#include "Player.h"
#include "sfWidget.h"


class TeamListItem : public Widget
{
public:
	TeamListItem(Pocemon &p, Game *game, Widget* parent = nullptr);
    TeamListItem(Pocemon &p, sf::Vector2f &pos, const float &scale, sf::Font &font, sf::Texture &texture);

    virtual bool updateSelf(const float &dt) override;

    void Render(sf::RenderWindow &window, int iFrame);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual sf::Vector2f getSize() const;

    // *******************************************************
    // *** Everything below will be private in the future: ***
    // *******************************************************
    Pocemon *poce;
    sf::Text nameText;
    sf::Sprite poceSprite;
    const int SPRITESIZE = 32;
	const float FRAMETIME = .5f;
    int iPoce;
	int iFrame = 0;
	float elapsedTime = 0.f;
    
    



};





#endif
