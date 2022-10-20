#include "ParticleSystem.h"
#include "Render.h"
#include "Physics.h"
#include "Time.h"
#include <iostream>
sf::VertexArray particles;
std::vector<sf::Vector2f> _positions;
std::vector<sf::Vector2f> _velocities;
std::vector<sf::Color> _colors;

ParticleSystem::ParticleSystem(int particleCount)
{
	for (int i = 0; i < particleCount; i++)
	{
		_positions.push_back(sf::Vector2f(i*5, 600));
		_velocities.push_back(sf::Vector2f(0.0f, 0.0f));
		_colors.push_back(sf::Color::White);

		particles.append(sf::Vertex(_positions[i], _colors[i]));
	}

	Render::addVertexArrayForRendering(&particles);
}

void ParticleSystem::update()
{
	for (int i = 0; i < _positions.size(); i++)
	{
		sf::Vector2f sumVelocity(0.0f, 0.0f);
		int particlesInRadius = 0;
		const float radius = 20.0f;
		int blue = 0;
		for (int j = 0; j < _positions.size(); j++)
		{
			if (i != j)
			{	
				auto temp = _positions[i] - _positions[j];
				auto dir = Physics::normalised(temp);
				auto magnitude = Physics::magnitude(temp);
				if (magnitude < radius) particlesInRadius++;
				if (magnitude < 2.0f)
				{
					_velocities[i] = -_velocities[i];
					blue = 255;
				}
				//auto push = dir / (magnitude * magnitude);
				//sumVelocity += push;
				//sumVelocity += pull;
			}
		}
		auto gravityVelocity = Physics::normalised(Physics::gravityWellPos - _positions[i]);
		_velocities[i] = _velocities[i] + gravityVelocity * 20.0f * (float)(Time::getDeltaTime());
		_velocities[i] = _velocities[i] + sumVelocity * 1.0f * (float)(Time::getDeltaTime());
		double deltaTime = Time::getDeltaTime();
		auto velocityDeltaTime = sf::Vector2f(_velocities[i].x * deltaTime, _velocities[i].y * deltaTime);

		_positions[i] = _positions[i] + velocityDeltaTime;
		_colors[i] = sf::Color(limitNumber(Physics::magnitude(_velocities[i])), limitNumber(particlesInRadius*15), blue, 255);

		particles[i].position = Render::worldSpaceToScreenSpace(_positions[i]);
		particles[i].color = _colors[i];
	}
}

int ParticleSystem::limitNumber(int x)
{
	return x < 155 ? 155 : (x > 255 ? 255 : x);
}
