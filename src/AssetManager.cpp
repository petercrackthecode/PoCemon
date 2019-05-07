#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "AssetManager.h"

void AssetManager::loadTexture(const TextureId &name, const std::string& filename)
{
    /* Load the texture */
    sf::Texture tex;
    tex.loadFromFile(filename);

    /* Add it to the list of textures */
    this->textures[name] = tex;

    return;
}

sf::Texture& AssetManager::getTextureRef(const TextureId &texture)
{
    return this->textures.at(texture);
}


void AssetManager::loadFont(const FontId &name, const std::string &filename)
{
    /* Load the font */
    sf::Font font;
    font.loadFromFile(filename);

    /* Add it to the list of font */
    this->fonts[name] = font;

    return;
}

sf::Font& AssetManager::getFontRef(const FontId &font)
{
    return this->fonts.at(font);
}
