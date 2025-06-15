#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include <random>


namespace Gameplay 
{
	class Board 
	{
	private:

		Cell* cell;

		std::string boardTexturePath = "assets/textures/board.png";
		sf::Texture boardTexture;
		sf::Sprite boardSprite;

		const float boardWidth = 720.0f;
		const float boardHeight = 1080.0f;
		const float boardPosition = 560.0f;

		std::string backgroundTexturePath = "assets/textures/minesweeper_bg.png";
		sf::Texture backgroundTexure;
		sf::Sprite backgroundSprite;
		float backgroundAlpha = 100.0f;

		static const int numberOfRows = 9;
		static const int numberOfColumns =9;

		const float horizontalCellPadding = 100.0f;
		const float verticalCellPadding = 329.0f;

		Cell* cells[numberOfRows][numberOfColumns];

		float getCellWidthInBoard() const;
		float getCellHeightInBoard() const;

		void creaeBoard();
		void initialize();
		void initializeBoardImage();
		void initializeBacground();

		std::default_random_engine randomEngine;
		std::random_device randomDevice;

		static const int totalMines = 9;

		void populateMines();
		void populateBoard();
		void initializeVariables();
	public:
		Board();
		void render(sf::RenderWindow& window);

	};
}
