#include "Render.h"
#include "PointRenderable.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Time.h"

sf::RenderWindow* Render::window;
std::vector<PointRenderable*> Render::renderablePoints;
sf::VertexArray Render::pointArray(sf::Points, 1);
sf::Vector2f Render::cameraPosition = sf::Vector2f(0.0f, 0.0f);
sf::Vector2f Render::scale = sf::Vector2f(1.0f, 1.0f);
sf::Vector2u Render::cameraSize;
std::vector<sf::VertexArray*> Render::vertexArraysToRender;

void Render::addRenderable(PointRenderable *rend, sf::PrimitiveType type)
{
	if (type == sf::Points)
	{
		Render::renderablePoints.push_back(rend);
		sf::Vertex point(rend->getScreenspacePosition(), rend->getColor());
		pointArray.append(point);
	}
}

sf::Vector2f Render::worldSpaceToScreenSpace(sf::Vector2f worldPos)
{
	float y = Render::cameraSize.y - worldPos.y * Render::scale.y + Render::cameraPosition.y * Render::scale.y;
	float x = worldPos.x * Render::scale.x - Render::cameraPosition.x * Render::scale.x;
	return sf::Vector2f(x, y);
}

void Render::setRenderWindow(sf::RenderWindow* window)
{
	Render::window = window;
	cameraSize = window->getSize();
}

void Render::render()
{
	// clear the window with black color
	Render::window->clear(sf::Color::Black);

	// update particles
	for (int i = 0; i < renderablePoints.size(); i++)
	{
		pointArray[i].position = renderablePoints[i]->getScreenspacePosition();
		pointArray[i].color = renderablePoints[i]->getColor();
	}

	window->draw(pointArray);
	
	for (int i = 0; i < vertexArraysToRender.size(); i++)
	{
		window->draw(*vertexArraysToRender[i]);
	}

	// end the current frame
	window->display();
}

void Render::addVertexArrayForRendering(sf::VertexArray* vertices)
{
	vertexArraysToRender.push_back(vertices);
}
