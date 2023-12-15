#include "Matrix.h"

void Matrix::UpdateCells(sf::RenderWindow* window)
{
	auto updatesVertexArray = vertexArray;
	auto updatesCellArray = grid;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			auto& currentCell = updatesCellArray[x][y];
			int aliveNeighbours = CellNeighbours(currentCell.Position, updatesCellArray);

			auto strategyActive = false;
			for (auto& strategy : strategies)
			{
				if (strategy->CheckCondition(currentCell.CheckState(), aliveNeighbours))
				{
					context.SetStrategy(strategy);
					strategyActive = true;
				}
			}
			if (strategyActive == false)
			{
				context.SetStrategy(ignoreStrategy);
			}

			context.PerformStrategy(currentCell);

			updatesVertexArray[x * height + y].color = currentCell.vertexColor;
		}
	}

	vertexArray = updatesVertexArray;
	grid = updatesCellArray;

	window->draw(&vertexArray[0], vertexArray.getVertexCount(), sf::Points);
}

void Matrix::SetRules()
{
	//Default Rules:
	strategies.push_back(new CellDieStrategy());
	strategies.push_back(new CellReviveStrategy());

	//Custom Rules 1: Revive when 2 exist, die when 3 or more exist, die when 1 or less exist.
	//strategies.push_back(new CustomDieStrategy1());
	//strategies.push_back(new CustomReviveStrategy1());

	//Custom Rules 2: Revive when 4 || 6 exist, die when aliveNeighbours >= 8 || aliveNeighbours <= 3.
	//strategies.push_back(new CustomDieStrategy2());
	//strategies.push_back(new CustomReviveStrategy2());

	ignoreStrategy = new IgnoreStrategy();
}

bool Matrix::CreateMatrix(int _width, int _height)
{
	width = _width;
	height = _height;

	vertexArray = sf::VertexArray();

	for (int i = 0; i < width; i++)
	{
		std::vector<Cell> row;

		for (int j = 0; j < height; j++)
		{
			Cell cell(sf::Vector2f(i, j));

			auto vertex = sf::Vertex();
			vertex.position = sf::Vector2f(i, j);
			vertex.color = cell.vertexColor;

			vertexArray.append(vertex);
			row.push_back(cell);
		}
		grid.push_back(row);
	}
	SetRules();
	return true;
}

int Matrix::CellNeighbours(sf::Vector2f position, std::vector<std::vector<Cell>>& grid) const
{
	auto amount = 0;

	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			int xPos = position.x + x;
			int yPos = position.y + y;

			if (y == 0 && x == 0)
			{
				continue;
			}
			if (yPos >= height || yPos < 0 || xPos >= width || xPos < 0)
			{
				continue;
			}
			if (!grid[xPos][yPos].CheckState())
			{
				continue;
			}

			amount++;
		}
	}
	return amount;
}