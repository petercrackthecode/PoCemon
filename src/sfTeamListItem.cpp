#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "sfTeamListItem.h"

TeamListItem::TeamListItem(Pocemon &p, Game *game, Widget* parent /*= nullptr*/)
	: poce{ &p }, iPoce{ static_cast<int>(poce->getId()) }, Widget{parent}
{
	//poceSprite.setPosition(sf::Vector2f(0.f, 0.f));
	poceSprite.setTexture(game->mAssetMgr.getTextureRef(TextureId::MiniPoceSprites));
	poceSprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoce), ((SPRITESIZE)* iFrame), SPRITESIZE, SPRITESIZE));
	//poceSprite.setScale(.5f, .5f);
	poceSprite.setPosition(5.f, poceSprite.getPosition().y);

	nameText.setFont(game->mAssetMgr.getFontRef(FontId::MainFont));
	nameText.setCharacterSize(24);
	nameText.setFillColor(sf::Color::Black);
	nameText.setScale(.2f, .2f);
	nameText.setOrigin(0.f, .5f);
	nameText.setPosition(sf::Vector2f(poceSprite.getGlobalBounds().width + 7.f, poceSprite.getGlobalBounds().height / 2.f));
	//nameText.setPosition(sf::Vector2f(SPRITESIZE + 2, 2));

	nameText.setString(poce->getName());
}

TeamListItem::TeamListItem(Pocemon &p, sf::Vector2f &pos, const float &scale, sf::Font &font, sf::Texture &texture)
	: poce{ &p }, iPoce{ static_cast<int>(poce->getId()) }
{
    //poceSprite.setPosition(pos);
    poceSprite.setTexture(texture);
    poceSprite.setScale(sf::Vector2f(scale/2, scale/2));
	poceSprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoce), ((SPRITESIZE)* iFrame), SPRITESIZE, SPRITESIZE));
    nameText.setFont(font);
    nameText.setCharacterSize(3*scale);
    nameText.setFillColor(sf::Color::White);
    //nameText.setPosition(sf::Vector2f(pos.x + SPRITESIZE* scale / 2 + scale, pos.y + scale*2));

	nameText.setString(poce->getName());
}


bool TeamListItem::updateSelf(const float &dt)
{
	bool textureChangeNeeded = false;
	elapsedTime += dt;
	
	if (elapsedTime > FRAMETIME)
	{
		if (iFrame == 0)
			iFrame = 1;
		else
			iFrame = 0;

		elapsedTime = 0;
		textureChangeNeeded = true;
	}

	if (iPoce != static_cast<int>(poce->getId()))
	{
		nameText.setString(poce->getName());
		textureChangeNeeded = true;
	}

	if (textureChangeNeeded)
	{
		poceSprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoce), ((SPRITESIZE)* iFrame), SPRITESIZE, SPRITESIZE));
	}
	
	return textureChangeNeeded;
}

void TeamListItem::Render(sf::RenderWindow &window, int iFrame)
{
    poceSprite.setTextureRect(sf::IntRect((SPRITESIZE*iPoce), ((SPRITESIZE)* iFrame), SPRITESIZE, SPRITESIZE));
    window.draw(nameText);
    window.draw(poceSprite);
}


//states.transform.translate(getPosition());

void TeamListItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());
	target.draw(nameText, states);
	target.draw(poceSprite, states);
}

 sf::Vector2f TeamListItem::getSize() const
{
	 return sf::Vector2f(nameText.getGlobalBounds().width + poceSprite.getGlobalBounds().width, poceSprite.getGlobalBounds().height);
}