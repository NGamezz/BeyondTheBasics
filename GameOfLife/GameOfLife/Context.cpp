#include "Context.h"

void Context::SetStrategy(Strategy* strategy)
{
	this->strategy = strategy;
}

void Context::PerformStrategy(Cell& cell) const
{
	strategy->Execute(cell);
}