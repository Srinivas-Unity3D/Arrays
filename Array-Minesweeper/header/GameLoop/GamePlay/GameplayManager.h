#pragma once
#include "Board.h"

namespace Gameplay 
{
	class GameplayManager 
	{
	private:
		Board* board;

		void initialize();
		void initializeVariables();

	public:
		GameplayManager();
		void render(sf::RenderWindow& window);
	};
}
