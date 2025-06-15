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

	float Board::getCellWidthInBoard() const
	{
		return (boardWidth - horizontalCellPadding)/numberOfColumns;
	}

	float Board::getCellHeightInBoard() const
	{
		return (boardHeight-verticalCellPadding)/numberOfRows;
	}

	void Board::creaeBoard()
	{
		float cellWidth = getCellWidthInBoard();
		float cellHeight = getCellHeightInBoard();

		for (int row = 0; row < numberOfRows; ++row) 
		{
			for (int col = 0; col < numberOfColumns; ++col) 
			{
				cells[row][col] = new Cell(cellWidth, cellHeight, sf::Vector2i(row, col));
			}
		}
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
		for (int row = 0; row < numberOfRows; row++)
		{
			for (int col = 0; col < numberOfColumns; col++) 
			{
				cells[row][col]->render(window);
			}
		}
	}
}