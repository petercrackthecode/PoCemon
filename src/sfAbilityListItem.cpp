#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "sfAbilityListItem.h"

AbilityListItem::AbilityListItem(Ability *a, Game *game, Widget* parent /*= nullptr*/)
	: ability{ a }, iType{ static_cast<int>(ability->getType()) }, Widget{ parent }
{
	nameText.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	nameText.setCharacterSize(24);
	nameText.setFillColor(sf::Color::Black);
	nameText.setScale(.2f, .2f);
	//nameText.setOrigin(0.f, .5f);
	nameText.setPosition(5.f, typeSprite.getPosition().y);

	//sf::Vector2f(typeSprite.getGlobalBounds().width + 7.f, typeSprite.getGlobalBounds().height / 2.f)
	typeSprite.setTexture(game->mAssetMgr.getTextureRef(TextureId::TypeLabels));
	typeSprite.setTextureRect(sf::IntRect(SPRITESIZE.x*iType, 0, SPRITESIZE.x, SPRITESIZE.y));
	typeSprite.setPosition(5.f, nameText.getGlobalBounds().height + 7.f);
	typeSprite.setScale(.5f, .5f);
	
	//nameText.setPosition(sf::Vector2f(SPRITESIZE + 2, 2));

	nameText.setString(ability->getName());

	powerText.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	powerText.setCharacterSize(24);
	powerText.setFillColor(sf::Color::Red);
	powerText.setScale(.2f, .2f);
	//nameText.setOrigin(0.f, .5f);
	powerText.setPosition(10.f + typeSprite.getGlobalBounds().width, .5f + typeSprite.getPosition().y);
	powerText.setString(std::to_string(ability->getPower()));
}

AbilityListItem::AbilityListItem(Ability *a, sf::Vector2f &pos, const float &scale, sf::Font &font, sf::Texture &texture)
	: ability{ a }, iType{ static_cast<int>(ability->getType()) }
{
	//typeSprite.setPosition(pos);
	typeSprite.setTexture(texture);
	typeSprite.setScale(sf::Vector2f(scale / 2, scale / 2));
	typeSprite.setTextureRect(sf::IntRect(SPRITESIZE.x*iType, 0, SPRITESIZE.x, SPRITESIZE.y));
	nameText.setFont(font);
	nameText.setCharacterSize(3 * scale);
	nameText.setFillColor(sf::Color::White);
	//nameText.setPosition(sf::Vector2f(pos.x + SPRITESIZE* scale / 2 + scale, pos.y + scale*2));

	nameText.setString(ability->getName());
}


void AbilityListItem::Render(sf::RenderWindow &window, int iFrame)
{
	//typeSprite.setTextureRect(sf::IntRect((SPRITESIZE*iType), ((SPRITESIZE)* iFrame), SPRITESIZE, SPRITESIZE));
	window.draw(nameText);
	window.draw(typeSprite);
}


//states.transform.translate(getPosition());

void AbilityListItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());
	target.draw(nameText, states);
	target.draw(typeSprite, states);
	target.draw(powerText, states);
}

sf::Vector2f AbilityListItem::getSize() const
{
	return sf::Vector2f(nameText.getGlobalBounds().width, typeSprite.getGlobalBounds().height + typeSprite.getGlobalBounds().height);
}