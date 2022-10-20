#pragma once
#include <SFML/Graphics.hpp>

class Physicsable
{
	public:
		void virtual updatePhysics();
		sf::Vector2f virtual getPosition() = 0;
		Physicsable();
};

