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
		if(button) button->render(game_window);
	}

}