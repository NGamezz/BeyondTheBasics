#include "CustomDieStrategy2.h"

void CustomDieStrategy2::Execute(Cell& cell)
{
	cell.SetActive(false);
}

bool CustomDieStrategy2::CheckCondition(bool state, int aliveNeighbours) const
{
	if (state == true && (aliveNeighbours >= 8 || aliveNeighbours <= 3))
	{
		return true;
	}
	return false;
}
