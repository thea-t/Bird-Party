#ifndef COLLISIONMATH_H
#define COLLISIONMATH_H

#include <SFML/Graphics.hpp>
#include <iostream>
float getRadius(sf::Sprite* sprite)
{
	return (float)sprite->getTextureRect().height * sprite->getScale().y / 2;

}

//how to calculate the distance between two points: https://www.geeksforgeeks.org/program-calculate-distance-two-points/
float getDistance(sf::Vector2f* a, sf::Vector2f* b) {

	float distance = std::sqrt(std::pow(b->x - a->x, 2) +
		std::pow(b->y - a->y, 2) * 1.0);
	return distance;
}

#endif