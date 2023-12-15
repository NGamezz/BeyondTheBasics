#pragma once

#include "Strategy.h"

class GenericStrategy : public Strategy
{
public:
	void Execute(Cell& cell) override;
	bool CheckCondition(bool condition, int aliveNeighbours) const override;
};