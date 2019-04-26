//
//  GameSprite.hpp
//  PoCemon
//
//  Created by Dung Nguyen on 4/24/19.
//  Copyright © 2019 Dung Nguyen. All rights reserved.
//

#ifndef GameSprite_hpp
#define GameSprite_hpp

#include <SFML/Graphics.hpp>

#include <stdio.h>
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

#endif /* GameSprite_hpp */
