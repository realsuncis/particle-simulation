#include "PointRenderable.h"
#include "Render.h"

sf::Vector2f screenSpacePosition;
sf::Vector2f worldSpacePosition;
sf::Color pointColor;

PointRenderable::PointRenderable(sf::Vector2f worldPos, sf::Color color)
{
	setWorldSpacePosition(worldPos);
	pointColor = color;
	Render::addRenderable(this, sf::Points);
}

sf::Vector2f PointRenderable::getScreenspacePosition()
{
	return screenSpacePosition;
}

sf::Color PointRenderable::getColor()
{
	return pointColor;
}

void PointRenderable::setWorldSpacePosition(sf::Vector2f position)
{
	float y = Render::cameraSize.y - position.y * Render::scale.y + Render::cameraPosition.y * Render::scale.y;
	float x = position.x * Render::scale.x - Render::cameraPosition.x * Render::scale.x;
	screenSpacePosition = sf::Vector2f(x, y);
	worldSpacePosition = position;
}
