#include "Particle.h"
#include "Time.h"
#include "Physics.h"


sf::Vector2f position;
sf::Vector2f velocity(0.0f, 0.0f);

Particle::Particle(sf::Vector2f position, sf::Color color) : PointRenderable(position, color)
{
	Particle::position = position;
}


void Particle::updatePhysics()
{
	
	//float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	//auto gravityVelocity = sf::Vector2f(sin((static_cast<long int> (time(NULL)))/1.0f)/10.0f, cos((static_cast<long int> (time(NULL))) / 1.0f) / 10.0f);
	//auto gravityVelocity = sf::Vector2f(0.02f + (r*2-1)/3, -0.0981f);
	/*auto objects = Physics::getObjects();
	sf::Vector2f sumVelocity(0.0f, 0.0f);
	for (auto obj : *objects)
	{
		if (obj != this)
		{
			auto temp = position - obj->getPosition();
			auto dir = Physics::normalised(temp);
			auto magnitude = Physics::magnitude(temp);
			auto push = dir/(magnitude*magnitude);
			//auto pull = -dir*log(magnitude);
			sumVelocity += push;
			//sumVelocity += pull;
		}
	}*/
	
	/*sf::Vector2f sumVelocity(0.0f, 0.0f);
	auto temp = position - Physics::getAveragePosition();
	auto dir = Physics::normalised(temp);
	auto magnitude = Physics::magnitude(temp);
	auto push = dir / (magnitude * magnitude);
	auto pull = -dir * magnitude;
	sumVelocity += push;
	sumVelocity += pull;*/
	auto gravityVelocity = Physics::normalised(Physics::gravityWellPos - position);
	velocity = velocity + gravityVelocity*50.0f*(float)(Time::getDeltaTime());
	//velocity = velocity + sumVelocity * 1.0f * (float)(Time::getDeltaTime());
	double deltaTime = Time::getDeltaTime();
	auto velocityDeltaTime = sf::Vector2f(velocity.x * deltaTime, velocity.y * deltaTime);

	position = position + velocityDeltaTime;
	setWorldSpacePosition(position);
}

sf::Vector2f Particle::getPosition()
{
	return position;
}
