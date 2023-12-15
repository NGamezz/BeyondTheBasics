#include "CustomDieStrategy1.h"

void CustomDieStrategy1::Execute(Cell& cell)
{
	cell.SetActive(false);
}

bool CustomDieStrategy1::CheckCondition(bool state, int aliveNeighbours) const
{
	if ((aliveNeighbours >= 3 || aliveNeighbours <= 1) && state == true)
	{
		return true;
	}
	return false;
}
