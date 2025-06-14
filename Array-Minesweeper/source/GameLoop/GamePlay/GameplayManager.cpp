#include "../../header/GameLoop/GamePlay/GameplayManager.h"


namespace Gameplay 
{
	GameplayManager::GameplayManager() 
	{
		initialize();
	}

	void GameplayManager::initialize() 
	{
		initializeVariables();
	}

	void GameplayManager::initializeVariables() 
	{
		board = new Board();
	}

	void GameplayManager::render(sf::RenderWindow& window) 
	{
		board->render(window);
	}
}