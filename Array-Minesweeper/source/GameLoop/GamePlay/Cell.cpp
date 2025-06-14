#include "../../header/GameLoop/GamePlay/Cell.h"


namespace Gameplay
{
	Cell::Cell(float width, float height, sf::Vector2i position)
	{
		initialize(width, height, position);
	}
	
	void Cell::initialize(float width, float height, sf::Vector2i position)
	{
		this->position = position;
		sf::Vector2f float_position(static_cast<float>(position.x), static_cast<float>(position.y));
		button = new UIElements::Button(cell_texture_path, float_position, width * slice_count, height);
	}

	void Cell::render(sf::RenderWindow& game_window)
	{
		setCellTexture();
		if(button) button->render(game_window);
	}

	CellState Cell::getCellState() const
	{
		return current_cell_state;
	}

	void Cell::setCellState(CellState cellState)
	{
		current_cell_state = cellState;
	}

	CellType Cell::getCellType() const
	{
		return cell_type;
	}

	void Cell::setCellType(CellType celltype)
	{
		cell_type = celltype;
	}

	void Cell::setCellTexture()
	{
		int index = static_cast<int>(cell_type);

		switch (current_cell_state)
		{
		case Gameplay::CellState::HIDDEN:
			button->setTextureRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
			break;
		case Gameplay::CellState::OPEN:
			button->setTextureRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
			break;
		case Gameplay::CellState::FLAGGED:
			button->setTextureRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
			break;
		default:
			break;
		}
	}

}