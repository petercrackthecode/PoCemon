#ifndef ABILITYLISTITEM_H
#define ABILITYLISTITEM_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "Ability.h"
#include "Player.h"
#include "sfWidget.h"


class AbilityListItem : public Widget
{
public:
	AbilityListItem(Ability *a, Game *game, Widget* parent = nullptr);
	AbilityListItem(Ability *a, sf::Vector2f &pos, const float &scale, sf::Font &font, sf::Texture &texture);

	//virtual bool updateSelf(const float &dt) override;

	void Render(sf::RenderWindow &window, int iFrame);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual sf::Vector2f getSize() const;

	// *******************************************************
	// *** Everything below will be private in the future: ***
	// *******************************************************
	Ability *ability;
	sf::Text nameText;
	sf::Text powerText;
	sf::Sprite typeSprite;
	const sf::Vector2i SPRITESIZE = sf::Vector2i(32, 14);
	int iType;





};





#endif
