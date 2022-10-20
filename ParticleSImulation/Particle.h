#pragma once
#include "Physicsable.h"
#include "PointRenderable.h"
#include <SFML/Graphics.hpp>
class Particle : virtual public Physicsable, public PointRenderable
{
	private:
		sf::Vector2f position;
		sf::Vector2f velocity;

	public:
		Particle(sf::Vector2f position, sf::Color color);
		void updatePhysics();
		sf::Vector2f getPosition();
};

