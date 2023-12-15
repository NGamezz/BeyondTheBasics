#include "CustomReviveStrategy1.h"

void CustomReviveStrategy1::Execute(Cell& cell)
{
	cell.SetActive(true);
}

bool CustomReviveStrategy1::CheckCondition(bool state, int aliveNeighbours) const
{
	if (aliveNeighbours == 2 && state == false)
	{
		return true;
	}

	return false;
}
