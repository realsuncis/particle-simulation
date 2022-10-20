#include "Physics.h"
#include <SFML\Graphics.hpp>
std::vector<Physicsable*> Physics::physicsableObjects;
sf::Vector2f Physics::gravityWellPos = sf::Vector2f(0.0f, 0.0f);
sf::Vector2f Physics::averagePosition = sf::Vector2f(0.0f, 0.0f);
void Physics::update()
{
	for (auto obj : physicsableObjects) obj->updatePhysics();
}

void Physics::preUpdate()
{
	sf::Vector2f sumPos(0.0f, 0.0f);
	for (auto obj : physicsableObjects) sumPos += obj->getPosition();
	averagePosition = sumPos / (float)physicsableObjects.size();
}

std::vector<Physicsable*>* Physics::getObjects()
{
	return &physicsableObjects;
}

void Physics::addPhysicsable(Physicsable* obj)
{
	physicsableObjects.push_back(obj);
}

void Physics::setGravityPos(sf::Vector2f position)
{
	gravityWellPos = position;
}

sf::Vector2f Physics::normalised(sf::Vector2f vec)
{
	double magnitude = Physics::magnitude(vec);
	return sf::Vector2f(vec.x/magnitude, vec.y/magnitude);
}

sf::Vector2f Physics::getAveragePosition()
{
	return averagePosition;
}

float Physics::magnitude(sf::Vector2f vec)
{
	return sqrt(vec.x*vec.x + vec.y*vec.y);
}


