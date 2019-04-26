#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <SFML/Graphics.hpp>
#include <string>

class GameSprite    {
private:
    sf::Sprite mSprite;
    sf::Texture texture;
public:
    GameSprite(std::string spritePath)    {
        texture.loadFromFile(spritePath);
        mSprite.setTexture(texture);
    }
};

#endif /* GAMESPRITE_H */
