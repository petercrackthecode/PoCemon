// Adapted from: SFML Blueprints By Maxime Barbier, 2015.

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

enum class TextureId
{
    None,
    BattleMenuBorder,
    MenuBackground,
    MenuExit,
    MenuLogo,
    MenuPlay,
    MiniPoceSprites,
    PoceSprites,
    TypeLabels
};

enum class FontId
{
    None,
    MainFont
};


class AssetManager
{
public:
    AssetManager() {}

    /* Add a texture from a file */
    void loadTexture(const TextureId &texture, const std::string &filename);

    /* Translate an TextureId into a reference to a texture */
    sf::Texture& getTextureRef(const TextureId &asset);



    /* Add a font from a file */
    void loadFont(const FontId &asset, const std::string &filename);

    /* Translate an FontId into a reference to a font */
    sf::Font& getFontRef(const FontId &asset);
    

private:
    std::map<TextureId, sf::Texture> textures;
    std::map<FontId, sf::Font> fonts;

};

#endif /* ASSETMANAGER_H */