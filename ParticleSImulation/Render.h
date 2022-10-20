#pragma once
#include "PointRenderable.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Render
{
	private:
		static sf::RenderWindow* window;
		static std::vector<PointRenderable*> renderablePoints;
		static sf::VertexArray pointArray;
		static std::vector<sf::VertexArray*> vertexArraysToRender;
		static int pointCount;

	public:
		static sf::Vector2f cameraPosition;
		static sf::Vector2u cameraSize;
		static sf::Vector2f scale;
		static void render();
		static void addVertexArrayForRendering(sf::VertexArray* vertices);
		static void setRenderWindow(sf::RenderWindow* window);
		static void addRenderable(PointRenderable *rend, sf::PrimitiveType type);
		static sf::Vector2f worldSpaceToScreenSpace(sf::Vector2f worldPos);

};

