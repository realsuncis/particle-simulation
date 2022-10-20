#pragma once
#include "Physicsable.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Physics
{
	private:
		static std::vector<Physicsable*> physicsableObjects;
		static sf::Vector2f averagePosition;
	public:
		static void update();
		static void preUpdate();
		static std::vector<Physicsable*>* getObjects();
		static void addPhysicsable(Physicsable* obj);
		static void setGravityPos(sf::Vector2f position);
		static sf::Vector2f normalised(sf::Vector2f vec);
		static sf::Vector2f getAveragePosition();
		static float magnitude(sf::Vector2f vec);
		static sf::Vector2f gravityWellPos;
};

