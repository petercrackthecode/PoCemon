//
//  Player.hpp
//  PoCemon
//
//  Created by Dung Nguyen on 4/21/19.
//  Copyright © 2019 Dung Nguyen. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "PoCemon.h"
#include "Enums.h"

#include <stdio.h>
#include <iostream>

class Player    {
private:
    std::string mName;
    int mScore;
    Pocemon * mPokemonList[6];
public:
    Player()    {
        mName= "";
        mScore= 0;
        mPokemonList[0]= nullptr;
    }
    
    Player(std::string name, int score) : mName(name), mScore(score)   {
        
    }
    
    std::string getName() const;
    int getScore() const;
    Pocemon * getPokemonList() const;
    Pocemon & findPokemon(const PkmnId &id);
    
    bool isInitialized() const;
};

#endif /* Player_hpp */
