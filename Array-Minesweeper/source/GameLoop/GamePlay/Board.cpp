#include "../../header/GameLoop/GamePlay/Board.h"


namespace Gameplay 
{
	Board::Board()
	{
		initialize();
	}

	void Board::initialize()
	{
		initializeBoardImage();

		initializeBacground();
		initializeVariables();

		creaeBoard();

		populateBoard();
	}

	void Board::initializeVariables()
	{
		randomEngine.seed(randomDevice());
	}

	void Board::populateMines()
	{
		std::uniform_int_distribution<int> x_dist(0, numberOfRows - 1);
		std::uniform_int_distribution<int> y_dist(0, numberOfColumns - 1);
		int placedMines = 0;

		while (placedMines < totalMines)
		{
			int x = x_dist(randomEngine);
			int y = y_dist(randomEngine);

			if (cells[x][y]->getCellType() != CellType::MINE) 
			{
				cells[x][y]->setCellType(CellType::MINE);
				placedMines++;
			}
		}
	}
	void Board::populateBoard()
	{
		populateMines();
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