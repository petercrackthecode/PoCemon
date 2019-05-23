
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameState.h"
#include "Player.h"

Game::Game(const sf::VideoMode &videoMode,
           const std::string &appName,
           const int &setting /*= sf::Style::Default*/)
    : mWindow{ videoMode, "PoCemon", setting }
{
    mWindow.setFramerateLimit(60);
    mWindow.setKeyRepeatEnabled(false);
    sf::View view(sf::FloatRect(0, 0, 480, 270));
    mWindow.setView(view);
	
    mAssetMgr.loadFont(FontId::MainFont, "graphics/gbFont.ttf");
    mAssetMgr.loadTexture(TextureId::BattleMenuBorder, "graphics/menu-border-pkbll.png");
    mAssetMgr.loadTexture(TextureId::MenuBackground, "graphics/background.png");
    mAssetMgr.loadTexture(TextureId::MenuExit, "graphics/button_exit.png");
    mAssetMgr.loadTexture(TextureId::MenuLogo, "graphics/PoCemon++ Logo2.png");
    mAssetMgr.loadTexture(TextureId::MenuPlay, "graphics/button_play.png");
    mAssetMgr.loadTexture(TextureId::MiniPoceSprites, "graphics/gen1-mini-sprites.png");
    mAssetMgr.loadTexture(TextureId::PoceSprites, "graphics/gen1-sprites.png");
    mAssetMgr.loadTexture(TextureId::TypeLabels, "graphics/PoCemonTypes.png");
}


void Game::run()    {
    sf::Clock clock;
    
    while (mWindow.isOpen())    {
        sf::Time deltaTime= clock.restart();
        float dt = deltaTime.asSeconds();

        if (peekState() == nullptr)
            continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->mWindow.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->mWindow.display();

        // After get events from user, update game state, then render images
        //processEvents();
        //update(deltaTime);
        //render();
    }
}

void Game::processEvents()  {
    sf::Event event;
    while (mWindow.pollEvent(event))    {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)  {
    
}

void Game::draw()   {
    
}

void Game::update(sf::Time deltaTime)   {
    sf::Vector2f movement(0.f, 0.f);
    
    // movement processing
    
    // movement result
}

void Game::render() {
    mWindow.clear();
    //mWindow.draw(mPlayer);
    mWindow.display();
}


void Game::pushState(GameState* state)
{
    this->states.push(state);

    return;
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState* state)
{
    if (!this->states.empty())
        popState();
    pushState(state);

    return;
}

GameState* Game::peekState()
{
    if (this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::setLetterboxView(int windowWidth, int windowHeight)
{
	// Source: https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view
	// Compares the aspect ratio of the window to the aspect ratio of the view,
	// and sets the view's viewport accordingly in order to archieve a letterbox effect.
	// A new view (with a new viewport set) is returned.

	float windowRatio = windowWidth / (float)windowHeight;
	float viewRatio = mWindow.getView().getSize().x / (float)mWindow.getView().getSize().y;
	float sizeX = 1;
	float sizeY = 1;
	float posX = 0;
	float posY = 0;

	bool horizontalSpacing = true;
	if (windowRatio < viewRatio)
		horizontalSpacing = false;

	// If horizontalSpacing is true, the black bars will appear on the left and right side.
	// Otherwise, the black bars will appear on the top and bottom.

	if (horizontalSpacing) {
		sizeX = viewRatio / windowRatio;
		posX = (1 - sizeX) / 2.f;
	}

	else {
		sizeY = windowRatio / viewRatio;
		posY = (1 - sizeY) / 2.f;
	}

	sf::View newView(sf::FloatRect(0, 0, 480, 270));
	newView.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

	mWindow.setView(newView);
}


void Game::toggleFullscreen()
{
	if (isFullscreen)
	{

		mWindow.create(sf::VideoMode(1280, 720), "PoCemon++", sf::Style::Default);
		mWindow.setFramerateLimit(60);
		mWindow.setKeyRepeatEnabled(false);
		sf::View view(sf::FloatRect(0, 0, 480, 270));
		mWindow.setView(view);
	}
	else
	{
		mWindow.create(sf::VideoMode(1920, 1080), "PoCemon++", sf::Style::Fullscreen);
		mWindow.setFramerateLimit(60);
		mWindow.setKeyRepeatEnabled(false);
		sf::View view(sf::FloatRect(0, 0, 480, 270));
		mWindow.setView(view);
	}
	isFullscreen = !isFullscreen;
}
