#pragma once

#include "Strategy.h"

class CustomReviveStrategy1 : public Strategy
{
public:
	void Execute(Cell& cell) override;
	bool CheckCondition(bool state, int aliveNeighbours) const override;
};