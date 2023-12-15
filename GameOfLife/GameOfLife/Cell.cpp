#include "Cell.h"

void Cell::SetActive(bool state)
{
	isActive = state;
	vertexColor = state ? sf::Color::White : sf::Color::Black;
}

bool Cell::CheckState() const
{
	return isActive;
}

Cell::Cell(sf::Vector2f position)
{
	Position = position;

	int random = std::rand();
	SetActive((random % 2));
}
