#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

bool isEscPressed();

void nothing()
{
    sf::RenderWindow window(sf::VideoMode(200,200), "Hello World");
    sf::CircleShape shape(100.f);
    shape.setPointCount(128);
    shape.setFillColor(sf::Color::Green);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(shape);
        window.display();
    }
}

void peter()  {
    // Create a video mode object
    sf::VideoMode vm(2000, 1200);
    
    // Create and open a window for the game
    sf::RenderWindow window(vm, "PoCemon");
    
    // Create a texture to hold a graphic on the GPU
    Texture textureBackground;
    
    // Load a graphic into the texture
    textureBackground.loadFromFile("/Users/dungnguyen/Documents/C++_directory/PoCemon/PoCemon/graphics/background.png");
    
    // Create a sprite
    Sprite spriteBackground;
    
    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);
    
    // Set the spriteBackground to cover the screen
    spriteBackground.setPosition(0, 0);
    
    Texture textureLogo;
    textureLogo.loadFromFile("/Users/dungnguyen/Documents/C++_directory/PoCemon/PoCemon/graphics/PoCemon++ Logo.png");
    Sprite spriteLogo;
    spriteLogo.setTexture(textureLogo);
    spriteLogo.setPosition(460, 200);
    
    Texture texturePlayButton;
    texturePlayButton.loadFromFile("/Users/dungnguyen/Documents/C++_directory/PoCemon/PoCemon/graphics/button_play.png");
    
    Sprite spritePlayButton;
    spritePlayButton.setTexture(texturePlayButton);
    spritePlayButton.setPosition(630, 400);
    
    Texture textureExitButton;
    
    // Load 1 new texture
    textureExitButton.loadFromFile("/Users/dungnguyen/Documents/C++_directory/PoCemon/PoCemon/graphics/button_exit.png");
    
    // 3 New sprites withe the same texture
    Sprite spriteExitButton;
    spriteExitButton.setTexture(textureExitButton);
    
    // Position the clouds off screen
    spriteExitButton.setPosition(630, 500);
    
    while (window.isOpen()) {
        /*
         **********************************************************
         Handle the players input
         **********************************************************
         */
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || isEscPressed())
                window.close();
        }
        
        
        /*
         **********************************************************
         Update the scene
         **********************************************************
         */
        
        /*
         **********************************************************
         Draw the scene
         **********************************************************
         */
        
        // Clear everything from the last frame
        window.clear();
        
        // Draw our game scene here
        window.draw(spriteBackground);
        window.draw(spriteLogo);
        
        // Draw the button
        window.draw(spritePlayButton);
        window.draw(spriteExitButton);
        
        // Draw the insect
        
        // Show everything we just drew
        window.display();
        
    }
}

bool isEscPressed() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}
