#pragma once
#include <SFML/Graphics.hpp>



namespace UIElements 
{
	enum class ButtonType
	{
		LEFT_MOUSE_BUTTON,
		RIGHT_MOUSE_BUTTON
	};

	class Button 
	{
	private:
		sf::Texture button_texture;
		sf::Sprite button_sprite;

		void initialize(const std::string texturePath, const sf::Vector2f& position, float width, float height);

	public:
		Button(const std::string& texture_path, const sf::Vector2f& position, float width, float height);
		void render(sf::RenderWindow& game_window) const;
	};
}