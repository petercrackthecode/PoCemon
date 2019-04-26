//
//  Player.cpp
//  PoCemon
//
//  Created by Dung Nguyen on 4/21/19.
//  Copyright © 2019 Dung Nguyen. All rights reserved.
//

#include "Player.hpp"

std::string Player::getName() const {
    return mName;
}

int Player::getScore() const    {
    return mScore;
}

void addPokemon(const Pocemon & pokemon)    {
    
}

Pocemon & findPokemon(std::string name) {
    Pocemon foundPocemon= Pocemon();
    
    if (!isInitialized) return
    
    for (int i=0; i < 6; i++)   {
        if (mPokemonList[i].getName() == name)  {
            
            break;
        }
    }
}
