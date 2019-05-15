#include <iostream>
#include "PoCemon.h"
#include "PoCemonData.h"
#include "AttackAbility.h"
#include "Enums.h"
#include "Player.h"
#include "randomGenerator.h"
#include "AbilityFactory.h"
#include "Battle.h"
#include "sfTeamListItem.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>

using namespace std;

void tayGraphicsTest();
void tayGraphicsAndBattleTest();

using namespace std;

		void kate() {

			string p1Name;
			string p2Name;

			cout << "Enter each player's name." << endl;
			cout << "Player 1: ";
			cin >> p1Name;
			cout << "Player 2: ";
			cin >> p2Name;

			Player p1(p1Name);
			Player p2(p2Name);

			Battle b(p1, p2);

			p1.generateRandomTeam();
			p2.generateRandomTeam();


			const int SPRITESIZE = 64;
			sf::RenderWindow window(sf::VideoMode(1280, 720), "PoCemon"/*, sf::Style::Fullscreen*/);
			window.setKeyRepeatEnabled(false);
			window.setFramerateLimit(60);
			int screenW = window.getSize().x;
			int screenH = window.getSize().y;
			float fScale = screenH / 150.f;
			sf::Vector2f scale(fScale, fScale);
			sf::Vector2f scaleLeft(-fScale, fScale);
			sf::Vector2f scaleRight(fScale, fScale);
			sf::Vector2f spriteOrigin(0, 0);
			sf::Vector2f spriteOriginLeft(0, 0);
			sf::Vector2f spriteOriginRight(SPRITESIZE, 0);
			sf::Vector2f spriteOriginMid((SPRITESIZE) / 2.f, (SPRITESIZE) / 2.f);

			// Setup the font
			sf::Font font;
			if (!font.loadFromFile("graphics/gbFont.ttf"))
			{
				// error...
			}
			sf::Text text;
			text.setFont(font);
			//text.setString("Arrow Keys: Move ---- Space: Animate ---- CTRL/ALT: Switch PoCemon");
			text.setCharacterSize(3 * fScale);
			text.setFillColor(sf::Color::White);

			sf::Text bEvtMsg;
			bEvtMsg.setFont(font);
			bEvtMsg.setCharacterSize(3 * fScale);
			bEvtMsg.setFillColor(sf::Color::White);
			BattleEvent bEvtCurrent;
			BattleEvent evtTemp;

			sf::Text p1PoceNameText;
			p1PoceNameText.setFont(font);
			p1PoceNameText.setString(p1.getActivePocemon()->getName());

			p1PoceNameText.setCharacterSize(3 * fScale);
			p1PoceNameText.setFillColor(sf::Color::White);
			p1PoceNameText.setPosition(sf::Vector2f(6.f * fScale, 6.f * fScale));

			sf::Text p2PoceNameText;
			p2PoceNameText.setFont(font);
			p2PoceNameText.setString(p2.getActivePocemon()->getName());
			p2PoceNameText.setCharacterSize(3 * fScale);
			p2PoceNameText.setFillColor(sf::Color::White);
			p2PoceNameText.setPosition(sf::Vector2f(screenW - 6.f * fScale - p2PoceNameText.getLocalBounds().width, 6.f * fScale));
            cin.get();
			
			}

