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
	AppStage currentStage = AppStage::CHESS;

	sf::RenderWindow window(sf::VideoMode(1600, 1200), L"Games!", sf::Style::Default);

	window.setVerticalSyncEnabled(true);

	

	while (window.isOpen()) {
		switch (currentStage)
		{
		case AppStage::MENU:
		{
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