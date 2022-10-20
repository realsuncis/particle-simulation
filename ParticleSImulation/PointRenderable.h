#pragma once
#include <SFML/Graphics.hpp>

class PointRenderable
{
	public:
		PointRenderable(sf::Vector2f worldPos, sf::Color color);
		sf::Vector2f getScreenspacePosition();
		sf::Color getColor();
		void setWorldSpacePosition(sf::Vector2f);
	protected:
		sf::Vector2f screenSpacePosition;
		sf::Vector2f worldSpacePosition;
		sf::Color pointColor;

};

