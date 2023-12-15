#include "CustomReviveStrategy2.h"

void CustomReviveStrategy2::Execute(Cell& cell)
{
	cell.SetActive(true);
}

bool CustomReviveStrategy2::CheckCondition(bool state, int aliveNeighbours) const
{
	if ((aliveNeighbours == 4 || aliveNeighbours == 6) && state == false)
	{
		return true;
	}
	return false;
}
