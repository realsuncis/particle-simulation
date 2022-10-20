#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class ParticleSystem
{
	public:
		ParticleSystem(int particleCount);
		void update();
	private:
		sf::VertexArray particles;
		std::vector<sf::Vector2f> _positions;
		std::vector<sf::Vector2f> _velocities;
		std::vector<sf::Color> _colors;
		int limitNumber(int x);
};

