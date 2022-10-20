#include <SFML/Graphics.hpp>
#include "Render.h"
#include "Particle.h"
#include "Physics.h"
#include "Time.h"
#include "ParticleSystem.h"
#include <chrono>
#include <thread>
#include <iostream>

const unsigned int W = 1366;
const unsigned int H = 768;
const unsigned int particleCount = 2;

int main()
{
	srand(static_cast <unsigned> (time(0)));
	// create the window
	sf::RenderWindow window(sf::VideoMode(W, H), "My window");
	Render::setRenderWindow(&window);

	int particleCount = 500;

	Time::init(std::chrono::high_resolution_clock::now());

	ParticleSystem particleSys(particleCount);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == event.KeyPressed)
			{
				if (event.key.code == sf::Keyboard::M)
				{
					for (int i = 0; i < 100; i++)
						for (int j = 0; j < 100; j++)
						{
							particleCount++;
							auto particle1 = new Particle(sf::Vector2f(W / 2 + i * 10, H / 2 + j * 10), sf::Color::White);
						}
				}
				if (event.key.code == sf::Keyboard::N)
				{
					
				}

			}
			if (event.type == sf::Event::MouseMoved)
			{
				Physics::setGravityPos(sf::Vector2f(event.mouseMove.x, H - event.mouseMove.y));
			}
		}
		
		Physics::preUpdate();
		Physics::update();

		particleSys.update();

		Render::render();
		
		Time::setNewTime(std::chrono::high_resolution_clock::now());
		auto delta = Time::getDeltaTime();

		std::cout << "\rFPS: " << 1 / Time::getDeltaTime();
		std::cout << " s: " << Time::getDeltaTime();
		std::cout << " particles: " << particleCount;
	}

	return 0;
}