#pragma once
#include "Strategy.h"

class CellDieStrategy : virtual public Strategy
{
public:
	void Execute(Cell& cell) override;
	bool CheckCondition(bool state, int aliveNeighbours) const override;
};