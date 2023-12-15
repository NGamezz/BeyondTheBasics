#include "Matrix.h"

int main()
{
	auto width = 800;
	auto height = 800;

	auto matrix = Matrix();
	if (!matrix.CreateMatrix(width, height))
	{
		return 0;
	};
	std::cout << "Created Matrix\n";

	sf::RenderWindow window(sf::VideoMode(width, height), "Game Of Life Window");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::Black);

		matrix.UpdateCells(&window);

		window.display();
	}
}