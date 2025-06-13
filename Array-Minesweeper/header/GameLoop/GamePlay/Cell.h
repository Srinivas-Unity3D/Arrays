#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../UI/UIElements/Button/Button.h"

namespace Gameplay 
{
	class Cell 
	{
	 private:
		 sf::Vector2i position;

		 const int tile_size = 128;
		 const int slice_count = 12;
		 const std::string cell_texture_path = "assets/textures/cells.jpeg";

		 UIElements::Button* button;

		 void initialize(float width,float height, sf::Vector2i position);

	 public:
		 Cell(float width,float height, sf::Vector2i position);
		 ~Cell()=default;
		 void render(sf::RenderWindow& game_window);
	};
}
