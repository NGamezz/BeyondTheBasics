#pragma once

#include <cstdlib>
#include "time.h"
#include "SFML//Graphics.hpp"
#include <random>
#include <functional>

class Cell
{
public:
	void SetActive(bool state);
	bool CheckState() const;
	sf::Vector2f Position;
	sf::Color vertexColor;
	Cell(sf::Vector2f position);
private:
	bool isActive = true;
};