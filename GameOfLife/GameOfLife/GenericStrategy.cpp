#include "GenericStrategy.h"

void GenericStrategy::Execute(Cell& cell)
{
}

bool GenericStrategy::CheckCondition(bool state, int aliveNeighbours) const
{
	if (state)
	{
		return true;
	}
	return false;
}
