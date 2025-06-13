#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cell.h"


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


		void creaeBoard();
		void initialize();
		void initializeBoardImage();
		void initializeBacground();
	public:
		Board();
		void render(sf::RenderWindow& window);

	};
}
