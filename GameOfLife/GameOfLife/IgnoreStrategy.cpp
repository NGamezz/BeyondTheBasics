#include "IgnoreStrategy.h"

void IgnoreStrategy::Execute(Cell& cell)
{
}

bool IgnoreStrategy::CheckCondition(bool state, int aliveNeighbours) const
{
	return false;
}
