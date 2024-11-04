#pragma once
#include <iostream>
#include "App.h"
#include "AppStage.h"
#include "Chess.h"

AppStage App::SelectGame()
{
	std::cout << "Input name of game!\n";
	while (true) {
		std::string name;
		std::cin >> name;
		if (name == "Chess") {
			return AppStage::CHESS;
		}
		else {
			std::cout << "Uncorrect name! Try again, please!\n";
			continue;
		}
	}
}

void App::StartApp()
{
	AppStage currentStage = AppStage::MENU;

	sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), L"Games!", sf::Style::Default);

	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) {
		switch (currentStage)
		{
		case AppStage::MENU:
		{
			SFML_DrawMenu(window);
			std::cout << "<----- LIST OF GAMES ----->\n";
			for (int i = 0; i < Games.size(); ++i) std::cout << Games[i] << '\n';
			std::cout << "<------------------------->\n\n";
			currentStage = App::SelectGame();
			break;
		}
		case AppStage::CHESS:
		{
			Chess game;
			game.StartChess(window);
			currentStage = AppStage::MENU;
			break;
		}
		default:
			return;
		}
	}
}

int App::Get_WindowHeight()
{
	return WindowHeight;
}

int App::Get_WindowWidth()
{
	return WindowWidth;
}

void App::SFML_DrawMenu(sf::RenderWindow& window)
{
	sf::CircleShape shape(100.f, 3);
	shape.setPosition(100, 100);
	shape.setFillColor(sf::Color::Red);

	sf::Texture BackGroundTexture;
	BackGroundTexture.loadFromFile("Photo/Menu/Menu-Background.jpg");
	//BackGroundTexture.loadFromFile("Photo/Chess/ChessBoardBlack.jpg");
	sf::Sprite BackGroundSprite;
	BackGroundSprite.setTexture(BackGroundTexture);

	window.clear(sf::Color::Black);
	/*window.draw(shape);*/
	window.draw(BackGroundSprite);
	//window.draw(shape);
	window.display();
}
