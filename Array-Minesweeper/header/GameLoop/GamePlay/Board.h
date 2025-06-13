#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


namespace Gameplay 
{
	class Board 
	{
	private:

		std::string boardTexturePath = "assets/textures/board.png";
		sf::Texture boardTexture;
		sf::Sprite boardSprite;

		const float boardWidth = 500.0f;
		const float boardHeight = 720.0f;
		const float boardPosition = 560.0f;

		void initialize();
		void initializeBoardImage();

	public:
		Board();
		void render(sf::RenderWindow& window);

	};
}
