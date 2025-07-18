#include "../../header/GameLoop/GamePlay/Board.h"


namespace Gameplay 
{
	Board::Board() 
	{
		initialize();
		creaeBoard();
	}

	void Board::initialize()
	{
		initializeBoardImage();

		initializeBacground();
	}

	void Board::creaeBoard()
	{
		cell = new Cell(83, 83, sf::Vector2i(0, 0));
	}

	void Board::initializeBoardImage() 
	{
		if (!boardTexture.loadFromFile(boardTexturePath)) 
		{
			std::cout << "Failed to load sprite" << std::endl;
			return;
		}

		boardSprite.setTexture(boardTexture);
		boardSprite.setPosition(boardPosition, 0);
		boardSprite.setScale(boardWidth / boardTexture.getSize().x, boardHeight / boardTexture.getSize().y);
	}

	void Board::initializeBacground() 
	{
		if (!backgroundTexure.loadFromFile(backgroundTexturePath)) 
		{
			std::cout << "Failed to Load Background Image" << std::endl;
			return;
		}

		backgroundSprite.setTexture(backgroundTexure);
		backgroundSprite.setColor(sf::Color( 255, 255, 255, backgroundAlpha));
	}

	void Board::render(sf::RenderWindow& window) 
	{
		window.draw(backgroundSprite);
		window.draw(boardSprite);
		cell->render(window);
	}
}